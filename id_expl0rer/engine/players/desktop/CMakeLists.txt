cmake_minimum_required(VERSION 3.10)

project(desktop_player)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 98)

add_executable(${PROJECT_NAME} WIN32 ${PROJECT_SOURCE_DIR}/src/main.cpp
        ../../include/engine/player.h
        src/renderer.cpp
        ../../../app/src/app.cpp
        ../../include/engine/app.h include/desktop_renderer.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

include_directories(engine app ${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} app sfml-graphics)