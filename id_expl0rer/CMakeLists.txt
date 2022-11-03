cmake_minimum_required(VERSION 3.23)
project(id_expl0rer)

set(CMAKE_CXX_STANDARD 98)

include_directories(id_expl0rer
        "$ENV{VS90}/VC/ce/atlmfc/src/mfc"
        "$ENV{VS90}/VC/ce/include"
        "$ENV{VS90}/VC/ce/atlmfc/include"
        "$ENV{VS90}/SmartDevices/SDK/PocketPC2003/Include")

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 1)

add_executable(id_expl0rer WIN32
        id_expl0rer/id_expl0rer.cpp
        id_expl0rer/id_expl0rer.h
        id_expl0rer/id_expl0rerDoc.cpp
        id_expl0rer/id_expl0rerDoc.h
        id_expl0rer/id_expl0rerView.cpp
        id_expl0rer/id_expl0rerView.h
        id_expl0rer/MainFrm.cpp
        id_expl0rer/MainFrm.h
        id_expl0rer/Resourceppc.h
        id_expl0rer/stdafx.cpp
        id_expl0rer/stdafx.h
        id_expl0rer/id_expl0rerppc.rc
        id_expl0rer/res/id_expl0rerppc.rc2)
