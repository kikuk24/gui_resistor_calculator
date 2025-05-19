
// ResistorCalculator.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CResistorCalculatorApp:
// See ResistorCalculator.cpp for the implementation of this class
//

class CResistorCalculatorApp : public CWinApp
{
public:
	CResistorCalculatorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CResistorCalculatorApp theApp;
