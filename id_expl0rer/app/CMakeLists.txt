cmake_minimum_required(VERSION 3.5)

project(id_expl0rer)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)

target_link_libraries(id_expl0rer-linux id_expl0rer_engine)
target_link_libraries(id_expl0rer-wince id_expl0rer_engine)
include_directories(id_expl0rer_engine)