cmake_minimum_required(VERSION 3.5)

project(app)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)
include_directories()


add_library(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} engine)