cmake_minimum_required(VERSION 3.5)

project(id_expl0rer_engine)

set(CMAKE_CXX_STANDARD 98)

add_library(${PROJECT_NAME} src/engine.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

target_link_libraries(${PROJECT_NAME}
        PUBLIC

        PRIVATE

        )

add_subdirectory(players/desktop players/wristterm)