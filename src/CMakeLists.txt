cmake_minimum_required(VERSION 3.13)
set(BINARY ${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(
        SRC
        controller/application.cpp
        view/window.cpp
        view/frame.cpp
        controller/demo1.cpp
        view/view.cpp
        model/entity.cpp ../include/model/entity.hpp model/world.cpp ../include/model/world.hpp model/terrain.cpp ../include/model/terrain.hpp model/square.cpp ../include/model/square.hpp model/cube.cpp ../include/model/cube.hpp model/point.cpp ../include/model/point.hpp)
set(SRC ${SRC})

include_directories(../include BINARY)
add_library(${BINARY}_lib STATIC ${SRC})