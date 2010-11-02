cmake_minimum_required (VERSION 2.4)

set (PACKAGE pianobar)
set (VERSION 2010.10.07-dev)
project (${PACKAGE} C)

add_subdirectory (libpiano)
add_subdirectory (libwaitress)
add_subdirectory (libezxml)
add_subdirectory (src)
