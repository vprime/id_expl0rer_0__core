cmake_minimum_required(VERSION 3.5)

project(id_expl0rer)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)

add_executable(id_expl0rer-linux src/main.cpp)

find_package(OpenGL COMPONENTS OpenGL)
find_package(GLUT)
find_package(GLU)

if (${OpenGL_FOUND})
endif()

if (${GLUT_FOUND})
    add_dependencies(id_expl0rer-linux OpenGL::OpenGL)
    target_include_directories(id_expl0rer-linux PUBLIC ${GLUT_INCLUDE_DIRS} )
endif()
if (${GLU_FOUND})
    target_include_directories(id_expl0rer-linux PUBLIC ${GLU_INCLUDE_DIRS})
endif()

if (${OpenGL_FOUND} AND ${GLUT_FOUND})
    target_link_libraries(id_expl0rer-linux OpenGL::OpenGL ${GLUT_LIBRARY} ${GLU_LIBRARY})
endif()


target_link_libraries(id_expl0rer-linux id_expl0rer_engine)
target_link_libraries(id_expl0rer-wince id_expl0rer_engine)
include_directories(id_expl0rer_engine)