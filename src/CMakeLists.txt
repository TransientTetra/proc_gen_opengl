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
        model/opengl_interfacing/vbo.cpp
        model/opengl_interfacing/shader.cpp
        model/opengl_interfacing/vertex_shader.cpp
        model/opengl_interfacing/fragment_shader.cpp
        model/opengl_interfacing/shader_program.cpp
        model/opengl_interfacing/vao.cpp
        model/opengl_interfacing/ebo.cpp
        model/opengl_interfacing/mesh.cpp
        view/demo1_main_scene.cpp
        model/opengl_interfacing/camera.cpp
        model/opengl_interfacing/vertex.cpp
        model/height_map.cpp
        model/sinusoidal_map.cpp
        model/noise.cpp
        model/noise_map.cpp
        model/perlin_noise.cpp
        model/white_noise.cpp
        view/terrain_control_frame.cpp
        model/opengl_interfacing/light_source.cpp
        model/diamond_square_map.cpp
        view/camera_control_frame.cpp
        view/scene_3d.cpp
        view/camera_controller.cpp
        view/above_camera_controller.cpp
        view/flying_fps_camera_controller.cpp
        view/static_camera_controller.cpp
        view/movement.cpp
        view/standard_fps_movement.cpp
        model/voronoi_map.cpp
        model/entity_mesh_generator.cpp
        model/terrain_colorer.cpp
        controller/model_manipulator.cpp
        controller/world_manipulator.cpp
        model/erosion.cpp
        model/hydraulic_erosion.cpp
        view/erosion_control_frame.cpp
)
set(SRC ${SRC})

include_directories(../include BINARY)
add_library(${BINARY}_lib STATIC ${SRC})