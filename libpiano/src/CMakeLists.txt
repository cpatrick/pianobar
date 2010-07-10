configure_file (${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
	${CMAKE_CURRENT_BINARY_DIR}/config.h)

include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../../libwaitress/src
        ${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/../../libezxml/src)

option(BUILD_PIANO_SHARED "Build libpiano as a shared library." OFF)

if(BUILD_PIANO_SHARED)
  add_library (piano SHARED crypt.c piano.c xml.c)
  target_link_libraries (piano waitress ezxml)
else(BUILD_PIANO_SHARED)
  add_library (piano STATIC crypt.c piano.c xml.c)
  target_link_libraries (piano waitress ezxml)
endif(BUILD_PIANO_SHARED)
