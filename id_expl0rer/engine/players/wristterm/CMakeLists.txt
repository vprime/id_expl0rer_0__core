cmake_minimum_required(VERSION 3.5)

project(wristterm_player)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)

add_executable(${PROJECT_NAME} WIN32
        src/gwes-sample2.cpp
        src/gwes-sample2.h
        src/resourceppc.h
        src/stdafx.cpp
        src/stdafx.h
        src/gwes-sample2ppc.rc)

target_include_directories(${PROJECT_NAME}
        PUBLIC "$ENV{VS90}/VC/ce/include"
        PUBLIC "$ENV{VS90}/SmartDevices/SDK/PocketPC2003/Include")


target_compile_definitions(${PROJECT_NAME}
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

target_link_libraries(${PROJECT_NAME} id_expl0rer_engine)

include_directories(engine app)