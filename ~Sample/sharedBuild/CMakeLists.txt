cmake_minimum_required(VERSION 3.18.4)

project(sharedBuildSample)

set(CMAKE_CXX_STANDARD 98)

include_directories(source)

add_executable(sharedBuildSample-wince WIN32
        source/gwes-sample2.cpp
        source/gwes-sample2.h
        source/resourceppc.h
        source/stdafx.cpp
        source/stdafx.h
        source/gwes-sample2ppc.rc)

target_include_directories(sharedBuildSample-wince
        PUBLIC "$ENV{VS90}/VC/ce/include"
        PUBLIC "$ENV{VS90}/SmartDevices/SDK/PocketPC2003/Include")


target_compile_definitions(sharedBuildSample-wince
        PRIVATE -D_AFXDLL
        PRIVATE _DEBUG
        PRIVATE _WIN32_WCE=0x420
        PRIVATE UNDER_CE
        PRIVATE WIN32_PLATFORM_PSPC
        PRIVATE WINCE
        PRIVATE DEBUG
        PRIVATE _WINDOWS
        PRIVATE ARM
        PRIVATE _ARM_
        PRIVATE _UNICODE
        PRIVATE UNICODE
        PRIVATE POCKETPC2003_UI_MODEL
        )

set(CMAKE_MFC_FLAG 1)

add_executable(sharedBuildSample-linux source/main.cpp)


find_package(OpenGL COMPONENTS OpenGL)
find_package(GLUT)
find_package(GLU)

if (${OpenGL_FOUND})
endif()

if (${GLUT_FOUND})
    add_dependencies(sharedBuildSample-linux OpenGL::OpenGL)
    target_include_directories(sharedBuildSample-linux ${GLUT_INCLUDE_DIRS} )
endif()
if (${GLU_FOUND})
    target_include_directories(sharedBuildSample-linux ${GLU_INCLUDE_DIRS})
endif()

if (${OpenGL_FOUND} AND ${GLUT_FOUND})
    target_link_libraries(sharedBuildSample-linux OpenGL::OpenGL ${GLUT_LIBRARY} ${GLU_LIBRARY})
endif()


