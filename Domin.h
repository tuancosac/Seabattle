
// Domin.h : main header file for the Domin application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDominApp:
// See Domin.cpp for the implementation of this class
//

class CDominApp : public CWinApp
{
public:
	CDominApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDominApp theApp;
