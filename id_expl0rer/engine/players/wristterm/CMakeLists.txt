cmake_minimum_required(VERSION 3.5)

project(id_expl0rer)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)

add_executable(id_expl0rer-wince WIN32
        src/gwes-sample2.cpp
        src/gwes-sample2.h
        src/resourceppc.h
        src/stdafx.cpp
        src/stdafx.h
        src/gwes-sample2ppc.rc)

target_include_directories(id_expl0rer-wince
        PUBLIC "$ENV{VS90}/VC/ce/include"
        PUBLIC "$ENV{VS90}/SmartDevices/SDK/PocketPC2003/Include")


target_compile_definitions(id_expl0rer-wince
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


target_link_libraries(id_expl0rer-linux id_expl0rer_engine)
target_link_libraries(id_expl0rer-wince id_expl0rer_engine)
include_directories(id_expl0rer_engine)