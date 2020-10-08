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
        view/opengl_interfacing/vbo.cpp
        view/opengl_interfacing/shader.cpp
        view/opengl_interfacing/vertex_shader.cpp
        view/opengl_interfacing/fragment_shader.cpp
        view/opengl_interfacing/shader_program.cpp
        view/opengl_interfacing/vao.cpp
        view/opengl_interfacing/ebo.cpp
        view/opengl_interfacing/mesh.cpp
        view/main_scene_view.cpp
        view/opengl_interfacing/camera.cpp
        view/opengl_interfacing/vertex.cpp
        controller/entity_translator.cpp
        controller/terrain_translator.cpp
        model/height_map.cpp
        model/sinusoidal_map.cpp
        model/noise.cpp
        model/simplex_noise.cpp
        model/noise_map.cpp
        model/perlin_noise.cpp
        model/white_noise.cpp
        view/opengl_interfacing/above_camera.cpp
        view/opengl_interfacing/first_person_camera.cpp
)
set(SRC ${SRC})

include_directories(../include BINARY)
add_library(${BINARY}_lib STATIC ${SRC})