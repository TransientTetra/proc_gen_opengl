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
        view/opengl_interfacing/vbo.cpp
        view/opengl_interfacing/shader.cpp
        view/opengl_interfacing/vertex_shader.cpp
        view/opengl_interfacing/fragment_shader.cpp
        view/opengl_interfacing/shader_program.cpp
        view/opengl_interfacing/vao.cpp
        view/opengl_interfacing/ebo.cpp ../include/view/opengl_interfacing/ebo.hpp view/opengl_interfacing/rendered_model.cpp ../include/view/opengl_interfacing/rendered_model.hpp)
set(SRC ${SRC})

include_directories(../include BINARY)
add_library(${BINARY}_lib STATIC ${SRC})