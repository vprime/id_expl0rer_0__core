cmake_minimum_required(VERSION 3.23)
project(id_expl0rer)

set(CMAKE_CXX_STANDARD 98)

include_directories(id_expl0rer
        "$ENV{VS90}/VC/ce/include"
        "$ENV{VS90}/SmartDevices/SDK/PocketPC2003/Include")

add_definitions(-D_AFXDLL)
add_compile_definitions(_DEBUG _WIN32_WCE=0x420 UNDER_CE WIN32_PLATFORM_PSPC WINCE DEBUG _WINDOWS ARM _ARM_ _UNICODE UNICODE POCKETPC2003_UI_MODEL)
set(CMAKE_MFC_FLAG 1)

add_executable(gwes-sample2 WIN32
        gwes-sample2/gwes-sample2.cpp
        gwes-sample2/gwes-sample2.h
        gwes-sample2/resourceppc.h
        gwes-sample2/stdafx.cpp
        gwes-sample2/stdafx.h
        gwes-sample2/gwes-sample2ppc.rc)
