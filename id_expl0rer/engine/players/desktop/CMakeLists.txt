cmake_minimum_required(VERSION 3.10)

project(desktop_player)

set(CMAKE_CXX_STANDARD 98)

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCE_DIR}/src/main.cpp ../../include/engine/player.h src/renderer.cpp ../../../app/src/app.cpp ../../include/engine/app.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

find_package(OpenGL COMPONENTS OpenGL)
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} OpenGL::GL OpenGL::GLU)

add_subdirectory(external/freeglut)
target_include_directories(${PROJECT_NAME} PRIVATE external/freeglut/include)
target_link_libraries(${PROJECT_NAME} freeglut)

include_directories(engine app)
target_link_libraries(${PROJECT_NAME} app)