/*
Copyright (c) 2008-2009
	Lars-Dominik Braun <PromyLOPh@lavabit.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/* system includes */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <time.h>
#include <ctype.h>
/* open () */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/* tcset/getattr () */
#include <termios.h>

/* last.fm scrobbling library */
#include <wardrobe.h>

#include <pthread.h>

/* pandora.com library */
#include <piano.h>

#include "player.h"
#include "settings.h"
#include "main.h"
#include "terminal.h"
#include "config.h"
#include "ui.h"
#include "ui_readline.h"

int main (int argc, char **argv) {
	/* handles */
	PianoHandle_t ph;
	static struct audioPlayer player;
	BarSettings_t settings;
	pthread_t playerThread;
	WardrobeHandle_t wh;
	/* currently playing */
	PianoSong_t *curSong = NULL;
	PianoStation_t *curStation = NULL;
	WardrobeSong_t scrobbleSong;
	char doQuit = 0;
	/* polls */
	/* FIXME: max path length? */
	char ctlPath[1024];
	FILE *ctlFd = NULL;
	struct pollfd polls[2];
	nfds_t pollsLen = 0;
	char buf = '\0';
	BarKeyShortcut_t *curShortcut = NULL;
	/* terminal attributes _before_ we started messing around with ~ECHO */
	struct termios termOrig;

	BarUiMsg (MSG_NONE, "Welcome to " PACKAGE "!\n");

	/* save terminal attributes, before disabling echoing */
	BarTermSave (&termOrig);

	BarTermSetEcho (0);
	BarTermSetBuffer (0);
	/* init some things */
	ao_initialize ();
	PianoInit (&ph);
	WardrobeInit (&wh);
	BarSettingsInit (&settings);
	BarSettingsRead (&settings);

	/* init polls */
	polls[0].fd = fileno (stdin);
	polls[0].events = POLLIN;
	++pollsLen;

	BarGetXdgConfigDir (PACKAGE "/ctl", ctlPath, sizeof (ctlPath));
	/* FIXME: why is r_+_ required? */
	ctlFd = fopen (ctlPath, "r+");
	if (ctlFd != NULL) {
		polls[1].fd = fileno (ctlFd);
		polls[1].events = POLLIN;
		++pollsLen;
		BarUiMsg (MSG_INFO, "Control fifo at %s opened\n", ctlPath);
	}

	if (settings.username == NULL) {
                BarTermSetEcho(1);
                BarTermSetBuffer(1);  
	 	char nameBuf[100];
		BarUiMsg (MSG_QUESTION, "Username: ");
                BarReadlineStr (nameBuf, sizeof (nameBuf), 1, stdin);
		settings.username = strdup (nameBuf);
                BarTermSetBuffer(0);
                BarTermSetEcho(0);
	}
	if (settings.password == NULL) {
		char passBuf[100];
		BarUiMsg (MSG_QUESTION, "Password: ");
		BarReadlineStr (passBuf, sizeof (passBuf), 1, stdin);
		settings.password = strdup (passBuf);
	}

	if (settings.enableScrobbling) {
		wh.user = strdup (settings.lastfmUser);
		wh.password = strdup (settings.lastfmPassword);
	}

	/* setup control connection */
	if (settings.controlProxy != NULL) {
		char tmpPath[2];
		WaitressSplitUrl (settings.controlProxy, ph.waith.proxyHost,
				sizeof (ph.waith.proxyHost), ph.waith.proxyPort,
				sizeof (ph.waith.proxyPort), tmpPath, sizeof (tmpPath));
	}

	BarUiMsg (MSG_INFO, "Login... ");
	if (BarUiPrintPianoStatus (PianoConnect (&ph, settings.username,
			settings.password)) !=
			PIANO_RET_OK) {
		BarTermRestore (&termOrig);
		return 0;
	}
	BarUiMsg (MSG_INFO, "Get stations... ");
	if (BarUiPrintPianoStatus (PianoGetStations (&ph)) != PIANO_RET_OK) {
		BarTermRestore (&termOrig);
		return 0;
	}

	/* try to get autostart station */
	if (settings.autostartStation != NULL) {
		curStation = PianoFindStationById (ph.stations,
				settings.autostartStation);
		if (curStation == NULL) {
			BarUiMsg (MSG_ERR, "Error: Autostart station not found.\n");
		}
	}
	/* no autostart? ask the user */
	if (curStation == NULL) {
		curStation = BarUiSelectStation (&ph, "Select station: ", stdin);
	}
	if (curStation != NULL) {
		BarUiPrintStation (curStation);
	}

	/* little hack, needed to signal: hey! we need a playlist, but don't
	 * free anything (there is nothing to be freed yet) */
	memset (&player, 0, sizeof (player));

	while (!doQuit) {
		/* song finished playing, clean up things/scrobble song */
		if (player.mode == PLAYER_FINISHED_PLAYBACK) {
			scrobbleSong.length = player.songDuration / BAR_PLAYER_MS_TO_S_FACTOR;
			/* scrobble when >= nn% are played; use seconds, not
			 * milliseconds */
			if (scrobbleSong.length > 0 && settings.enableScrobbling &&
					player.songPlayed / BAR_PLAYER_MS_TO_S_FACTOR * 100 /
					scrobbleSong.length >= settings.lastfmScrobblePercent) {
				WardrobeReturn_t wRet;

				BarUiMsg (MSG_INFO, "Scrobbling song... ");
				if ((wRet = WardrobeSubmit (&wh, &scrobbleSong)) ==
						WARDROBE_RET_OK) {
					BarUiMsg (MSG_NONE, "Ok.\n");
				} else {
					BarUiMsg (MSG_ERR, "Error: %s\n",
							WardrobeErrorToString (wRet));
				}
			}
			WardrobeSongDestroy (&scrobbleSong);
			/* FIXME: pthread_join blocks everything if network connection
			 * is hung up e.g. */
			pthread_join (playerThread, NULL);
			memset (&player, 0, sizeof (player));
		}

		/* check whether player finished playing and start playing new
		 * song */
		if (player.mode >= PLAYER_FINISHED_PLAYBACK ||
				player.mode == PLAYER_FREED) {
			if (curStation != NULL) {
				/* what's next? */
				if (curSong != NULL) {
					curSong = curSong->next;
				}
				if (curSong == NULL) {
					PianoReturn_t pRet = PIANO_RET_ERR;

					BarUiMsg (MSG_INFO, "Receiving new playlist... ");
					PianoDestroyPlaylist (&ph);
					if ((pRet = BarUiPrintPianoStatus (PianoGetPlaylist (&ph,
							curStation->id, settings.audioFormat))) !=
							PIANO_RET_OK) {
						curStation = NULL;
					} else {
						curSong = ph.playlist;
						if (curSong == NULL) {
							BarUiMsg (MSG_INFO, "No tracks left.\n");
							curStation = NULL;
						}
					}
					BarUiStartEventCmd (&settings, "stationfetchplaylist",
							curStation, curSong, pRet);
				}
				/* song ready to play */
				if (curSong != NULL) {
					BarUiPrintSong (curSong, curStation->isQuickMix ?
							PianoFindStationById (ph.stations,
							curSong->stationId) : NULL);
					/* setup artist and song name for scrobbling (curSong
					 * may be NULL later) */
					WardrobeSongInit (&scrobbleSong);
					scrobbleSong.artist = strdup (curSong->artist);
					scrobbleSong.title = strdup (curSong->title);
					scrobbleSong.album = strdup (curSong->album);
					scrobbleSong.started = time (NULL);

					/* setup player */
					memset (&player, 0, sizeof (player));

					WaitressInit (&player.waith);
					WaitressSetUrl (&player.waith, curSong->audioUrl);

					player.gain = curSong->fileGain;
					player.audioFormat = curSong->audioFormat;
		
					/* throw event */
					BarUiStartEventCmd (&settings, "songstart", curStation,
							curSong, PIANO_RET_OK);

					/* start player */
					pthread_create (&playerThread, NULL, BarPlayerThread,
							&player);
				}
			} /* end if curStation != NULL */
		}

		/* in the meantime: wait for user actions;
		 * 1000ms == 1s => refresh time display every second */
		if (poll (polls, pollsLen, 1000) > 0) {
			FILE *curFd = NULL;

			if (polls[0].revents & POLLIN) {
				curFd = stdin;
			} else if (polls[1].revents & POLLIN) {
				curFd = ctlFd;
			}
			buf = fgetc (curFd);
			curShortcut = settings.keys;

			while (curShortcut != NULL) {
				if (curShortcut->key == buf) {
					curShortcut->cmd (&ph, &player, &settings, &curSong,
							&curStation, &doQuit, curFd);
					break;
				}
				curShortcut = curShortcut->next;
			}
		}

		/* show time */
		if (player.mode >= PLAYER_SAMPLESIZE_INITIALIZED &&
				player.mode < PLAYER_FINISHED_PLAYBACK) {
			/* Ugly: songDuration is unsigned _long_ int! Lets hope this won't
			 * overflow */
			int songRemaining = (signed long int) (player.songDuration - player.songPlayed)
					/ BAR_PLAYER_MS_TO_S_FACTOR;
			char pos = 0;
			if (songRemaining < 0) {
				/* Use plus sign if song is longer than expected */
				pos = 1;
				songRemaining = -songRemaining;
			}
			BarUiMsg (MSG_TIME, "%c%02i:%02i/%02i:%02i\r", (pos ? '+' : '-'),
					songRemaining / 60, songRemaining % 60,
					player.songDuration / BAR_PLAYER_MS_TO_S_FACTOR / 60,
					player.songDuration / BAR_PLAYER_MS_TO_S_FACTOR % 60);
		}
	}

	/* destroy everything (including the world...) */
	if (player.mode != PLAYER_FREED) {
		pthread_join (playerThread, NULL);
	}
	if (ctlFd != NULL) {
		fclose (ctlFd);
	}
	PianoDestroy (&ph);
	WardrobeDestroy (&wh);
	ao_shutdown();
	BarSettingsDestroy (&settings);

	/* restore terminal attributes, zsh doesn't need this, bash does... */
	BarTermRestore (&termOrig);

	return 0;
}
