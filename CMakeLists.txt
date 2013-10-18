cmake_minimum_required(VERSION 2.8)
project( CameraInput )
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")

find_package( FFMPEG REQUIRED )
include_directories(${FFMPEG_INCLUDE_DIR})
set(LIBS ${LIBS} ${FFMPEG_LIBRARIES})

find_package( OpenCV REQUIRED )
add_definitions(-D__STDC_CONSTANT_MACROS)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK2 REQUIRED gtk+-2.0)
include_directories (${GTK2_INCLUDE_DIRS})
link_directories (${GTK2_LIBRARY_DIRS})
add_definitions (${GTK2_CFLAGS_OTHER})

add_executable( CameraInput CameraInput.cpp )

target_link_libraries( CameraInput ${LIBS} )
target_link_libraries( CameraInput ${OpenCV_LIBS} )
target_link_libraries (CameraInput ${GTK2_LIBRARIES})
