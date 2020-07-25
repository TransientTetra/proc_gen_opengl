cmake_minimum_required(VERSION 3.13)
project(proc_gen_opengl)

set(CMAKE_CXX_STANDARD 17)

set(SDL2_LIBRARY ${CMAKE_SOURCE_DIR}/lib/sdl2/bin/SDL2.dll)
set(SDL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/sdl2/include)

set(GLEW_LIBRARY ${CMAKE_SOURCE_DIR}/lib/glew/bin/glew32.dll)
set(GLEW_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/lib/glew/include)

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(lib) #for imgui
include_directories(lib/imgui)
include_directories(lib/googletest/googletest/include)
include_directories(include)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib)
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib Threads::Threads ${SDL2_LIBRARY} opengl32 ${GLEW_LIBRARY} imgui)
