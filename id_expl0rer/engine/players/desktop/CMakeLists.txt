cmake_minimum_required(VERSION 3.10)

project(desktop_player)

set(CMAKE_CXX_STANDARD 98)


add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

find_package(OpenGL COMPONENTS OpenGL)
find_package(GLUT)

if (${OPENGL_GLU_FOUND})
    message("OpenGL:GLU found")
    message(${OPENGL_glu_LIBRARY})
endif()
if (${OPENGL_FOUND})
    message("OpenGL found")
    message(${OPENGL_gl_LIBRARY})
endif()
if (${OpenGL_OpenGL_FOUND})
    message("OpenGL:OpenGL found")
endif()

target_link_libraries(${PROJECT_NAME} ${OPENGL_glu_LIBRARY} ${OPENGL_gl_LIBRARY})

if (${GLUT_FOUND})
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLUT_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARY})
else()
    add_subdirectory(external/freeglut)
    target_include_directories(${PROJECT_NAME} PRIVATE external/freeglut/include)
    target_link_libraries(${PROJECT_NAME} freeglut)
endif()
if (${GLU_FOUND})
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLU_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${GLU_LIBRARY})
endif()


include_directories(engine app)
target_link_libraries(${PROJECT_NAME} app)