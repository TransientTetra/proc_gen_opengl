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
        model/entity.cpp
        model/world.cpp
        model/terrain.cpp
        model/square.cpp
        model/cube.cpp
        model/point.cpp
        view/vbo.cpp
        view/shader.cpp
        view/vertex_shader.cpp
        view/fragment_shader.cpp
        view/shader_program.cpp ../include/view/shader_program.hpp view/vao.cpp ../include/view/vao.hpp)
set(SRC ${SRC})

include_directories(../include BINARY)
add_library(${BINARY}_lib STATIC ${SRC})