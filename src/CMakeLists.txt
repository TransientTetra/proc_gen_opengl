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
        view/demo1_main_scene.cpp
        view/opengl_interfacing/camera.cpp
        view/opengl_interfacing/vertex.cpp
        model/height_map.cpp
        model/sinusoidal_map.cpp
        model/noise.cpp
        model/simplex_noise.cpp
        model/noise_map.cpp
        model/perlin_noise.cpp
        model/white_noise.cpp
        view/terrain_control_frame.cpp
        controller/world_manipulator.cpp
        controller/model_manipulator.cpp
        view/opengl_interfacing/light_source.cpp
        model/diamond_square_map.cpp
        view/camera_control_frame.cpp
        view/camera_view.cpp
        view/terrain_models_view.cpp
        view/camera_controller.cpp
        view/above_camera_controller.cpp
        view/flying_fps_camera_controller.cpp
        view/static_camera_controller.cpp
        view/movement.cpp
        view/standard_fps_movement.cpp
        model/voronoi_map.cpp
        model/entity_mesh_generator.cpp
        model/terrain_mesh_generator.cpp
)
set(SRC ${SRC})

include_directories(../include BINARY)
add_library(${BINARY}_lib STATIC ${SRC})