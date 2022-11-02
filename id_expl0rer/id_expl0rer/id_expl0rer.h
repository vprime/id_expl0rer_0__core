// id_expl0rer.h : main header file for the id_expl0rer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

// Cid_expl0rerApp:
// See id_expl0rer.cpp for the implementation of this class
//

class Cid_expl0rerApp : public CWinApp
{
public:
	Cid_expl0rerApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
public:
	afx_msg void OnAppAbout();

	DECLARE_MESSAGE_MAP()
};

extern Cid_expl0rerApp theApp;
