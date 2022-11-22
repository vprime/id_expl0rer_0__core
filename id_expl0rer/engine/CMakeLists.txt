cmake_minimum_required(VERSION 3.5)

project(engine)

set(CMAKE_CXX_STANDARD 98)

add_library(${PROJECT_NAME}
        src/engine.cpp
        include/engine/player.h
        ../app/src/app.cpp include/engine/app.h
        src/mainloop.cpp
        include/engine/core.h include/engine/graphics.h include/engine/math.h)

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

add_subdirectory(players/desktop)
add_subdirectory(players/wristterm)