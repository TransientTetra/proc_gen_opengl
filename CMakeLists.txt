cmake_minimum_required(VERSION 3.16)
project(proc_gen_opengl)

set(CMAKE_CXX_STANDARD 17)

set(ASSETS_FOLDER ${PROJECT_SOURCE_DIR}/assets)

if(WIN32)
    set(SDL2_LIBRARY ${PROJECT_SOURCE_DIR}/lib/sdl2/lib/libSDL2.a)
    set(SDL2_DLL_LIBRARY ${PROJECT_SOURCE_DIR}/lib/sdl2/bin/SDL2.dll)
    set(SDL2_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/sdl2/include)

    set(GLEW_LIBRARY ${PROJECT_SOURCE_DIR}/lib/glew/lib/glew32.lib)
    set(GLEW_DLL_LIBRARY ${PROJECT_SOURCE_DIR}/lib/glew/bin/glew32.dll)
    set(GLEW_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/glew/include)
else()
    find_package(SDL2 REQUIRED)
    find_library(GL_LIBRARY NAME GL)
    find_library(GLEW_LIBRARY NAME GLEW)
    set(SDL2_INCLUDE_DIR ${SDL2_INCLUDE_DIRS})
endif()

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(lib) #for imgui
include_directories(lib/imgui)
include_directories(lib/googletest/googletest/include)
include_directories(lib/glm)
include_directories(include)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})

add_subdirectory(src)
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_subdirectory(tst)
endif()
add_subdirectory(lib)
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib Threads::Threads imgui glm)
if(WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY} ${GLEW_DLL_LIBRARY} opengl32 hid winmm mingw32 kernel32
            imm32 msvcrt ole32 oleaut32 setupapi shell32 user32 version)
else()
    target_link_libraries(${CMAKE_PROJECT_NAME} SDL2 GLEW GL)
endif()

#copying dlls and assets
if(WIN32)
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${SDL2_DLL_LIBRARY} $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>)
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${GLEW_DLL_LIBRARY} $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>)
endif()
add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${ASSETS_FOLDER} $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/assets)

#installing, remember to install with release mode
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}) #this is temporary, to install project in source dir
install(TARGETS ${CMAKE_PROJECT_NAME}
        DESTINATION bin)
install(DIRECTORY ${ASSETS_FOLDER} DESTINATION bin)
if(WIN32)
    install(FILES ${SDL2_DLL_LIBRARY} ${GLEW_DLL_LIBRARY} DESTINATION bin)
endif()

