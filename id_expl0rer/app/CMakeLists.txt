cmake_minimum_required(VERSION 3.5)

project(app)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)

add_library(${PROJECT_NAME} src/app.cpp ../engine/include/engine/app.h include/id_expl0rer.h)
target_link_libraries(${PROJECT_NAME} engine)