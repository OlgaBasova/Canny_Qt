project(untitled_cmake_opencv)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set ( SOURCES
 main.cpp
 mainwindow.cpp
)

set ( MOC_HEADERS
 mainwindow.h
 ui_mainwindow.h
)

set ( UIS
 mainwindow.ui
)

add_executable( ${PROJECT_NAME} ${SOURCES} ${MOC_HEADERS} ${UIS})

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

qt5_use_modules(${PROJECT_NAME} Widgets)

find_package(OpenCV 3.4 REQUIRED PATHS "/home/number42/opencv-3.4.1")
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
