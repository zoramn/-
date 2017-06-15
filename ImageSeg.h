// ImageSeg.h : main header file for the IMAGESEG application
//

#if !defined(AFX_IMAGESEG_H__3CAC7B23_51FE_4C2D_9A4C_4D53731987A1__INCLUDED_)
#define AFX_IMAGESEG_H__3CAC7B23_51FE_4C2D_9A4C_4D53731987A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once//	c++编译器的版本号
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__   //判断是否二次定义afxwin.h这个文件，防止二次加载
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageSegApp:
// See ImageSeg.cpp for the implementation of this class
//

class CImageSegApp : public CWinApp
{
public:
	ULONG_PTR m_gdiplusToken;//Unsigned long type for pointer precision. Use when casting a pointer to a long type to perform pointer arithmetic. 

	CImageSegApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageSegApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CImageSegApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGESEG_H__3CAC7B23_51FE_4C2D_9A4C_4D53731987A1__INCLUDED_)
