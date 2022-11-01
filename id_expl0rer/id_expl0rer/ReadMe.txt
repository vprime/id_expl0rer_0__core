================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : id_expl0rer Project Overview
===============================================================================

The application wizard has created this id_expl0rer application for 
you.  This application not only demonstrates the basics of using the Microsoft 
Foundation Classes but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your id_expl0rer application.

id_expl0rer.vcproj
    This is the main project file for VC++ projects generated using an application wizard. 
    It contains information about the version of Visual C++ that generated the file, and 
    information about the platforms, configurations, and project features selected with the
    application wizard.

id_expl0rer.h
    This is the main header file for the application.  It includes other
    project specific headers and declares the Cid_expl0rerApp application class.

id_expl0rer.cpp
    This is the main application source file that contains the application
    class Cid_expl0rerApp.


id_expl0rerppc.rc
    This is the project's main resource file listing of all of the Microsoft Windows
    resources that the project uses when compiling for the Pocket PC platform, or a
    platform that supports the same user interface model.  It includes the icons,
    bitmaps, and cursors that are stored in the RES subdirectory.  This file can be 
    directly edited in Microsoft Visual C++. Your project resources are in 
    1033. When the .rc file is persisted, the defines in the data section
    are persisted as the hexadecimal version of the numeric value they are defined to
    rather than the friendly name of the define.

res\id_expl0rerppc.rc2
    This file contains resources that are not edited by Microsoft 
    Visual C++. You should place all resources not editable by
    the resource editor in this file.


res\id_expl0rer.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file.

id_expl0rer.reg
    This is an example .reg file that shows you the kind of registration
    settings the framework will set for you.  You can use this as a .reg
    file to go along with your application or just delete it and rely
    on the default RegisterShellFileTypes registration.

/////////////////////////////////////////////////////////////////////////////

For the main frame window:
    The project includes a standard MFC interface.

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CFrameWnd and controls all SDI frame features.


/////////////////////////////////////////////////////////////////////////////

The application wizard creates one document type and one view:

id_expl0rerDoc.h, id_expl0rerDoc.cpp - the document
    These files contain your Cid_expl0rerDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via Cid_expl0rerDoc::Serialize).
    The Document will have the following strings:
        File extension:      ix0
        File type ID:        idexpl0rer.Document
        Main frame caption:  id_expl0rer
        Doc type name:       id_expl0rer
        Filter name:         id_expl0rer Files (*.ix0)
        File new short name: id_expl0rer
        File type long name: id_expl0rer.Document

id_expl0rerView.h, id_expl0rerView.cpp - the view of the document
    These files contain your Cid_expl0rerView class.
    Cid_expl0rerView objects are used to view Cid_expl0rerDoc objects.




/////////////////////////////////////////////////////////////////////////////

Other Features:

   Command bar in main frame with menu and adornments

ActiveX Controls
    The application includes support to use ActiveX controls.

Windows Sockets
    The application has support for establishing communications over TCP/IP networks.

/////////////////////////////////////////////////////////////////////////////

Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named id_expl0rer.pch and a precompiled types file named StdAfx.obj.

Resourceppc.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

/////////////////////////////////////////////////////////////////////////////

Other notes:

The application wizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is in a 
language other than the operating system's current language, you will need 
to copy the corresponding localized resources MFC90XXX.DLL to your application
directory ("XXX" stands for the language abbreviation.  For example,
MFC90DEU.DLL contains resources translated to German.)  If you don't do this,
some of the UI elements of your application will remain in the language of the
operating system.

/////////////////////////////////////////////////////////////////////////////
