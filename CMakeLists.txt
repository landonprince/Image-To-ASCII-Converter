cmake_minimum_required(VERSION 3.28)
project(ImageToASCII)

set(CMAKE_CXX_STANDARD 20)
set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ImageToASCII main.cpp
        ImageToASCII.h
        ImageToASCII.cpp)

set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

target_link_libraries(ImageToASCII ${OpenCV_LIBS})