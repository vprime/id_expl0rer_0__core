cmake_minimum_required(VERSION 3.18.4)
project(linuxSample)

set(CMAKE_CXX_STANDARD 14)

add_executable(linuxSample main.cpp)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)
find_package(GLU REQUIRED)

add_dependencies(linuxSample OpenGL::OpenGL)

include_directories(${GLUT_INCLUDE_DIRS} )
include_directories(${GLU_INCLUDE_DIRS})

target_link_libraries(linuxSample OpenGL::OpenGL ${GLUT_LIBRARY} ${GLU_LIBRARY})