# Procedural generation in OpenGL
This project aims to provide tools for procedural generation of terrain with OpenGL rendering.

## Installing dependencies
### Windows
Precompiled libraries are attached to the project for Windows. User and developer should
not have to do any additional work.
### Linux
Currently the project relies on shared libraries on Linux. On Debian and Debian based
distros to install the required libraries use the following commands:
```shell script
sudo apt update
sudo apt install -y libsdl2-dev libopengl-dev libglew-dev
```

## Cloning the repository
To clone the project use following commands:
```shell script
git clone --recurse-submodules https://github.com/msperkow/proc_gen_opengl.git
cd proc_gen_opengl
git submodule init
git submodule update
```

