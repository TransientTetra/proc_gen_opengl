cmake_minimum_required(VERSION 3.13)
set(BINARY ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(
        SRC
        controller/application.cpp
        view/window.cpp
        view/frame.cpp)
set(SRC ${SRC})

include_directories(../include BINARY)
add_library(${BINARY}_lib STATIC ${SRC})