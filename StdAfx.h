// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E5762F75_F518_492C_9043_2A0BBF77C4B3__INCLUDED_)
#define AFX_STDAFX_H__E5762F75_F518_492C_9043_2A0BBF77C4B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#define ULONG_PTR void*

#include "include\memdc.h"
#include "cximage/include/ximage.h"  //////////////////////////////change
#pragma comment(lib, "cximage/lib/png.lib")  
#pragma comment(lib, "cximage/lib/libdcr.lib")  
#pragma comment(lib, "cximage/lib/jpeg.lib")  
#pragma comment(lib, "cximage/lib/zlib.lib")  
#pragma comment(lib, "cximage/lib/tiff.lib")  
#pragma comment(lib, "cximage/lib/jasper.lib")  
#pragma comment(lib, "cximage/lib/cximage.lib")  
#pragma comment(lib, "cximage/lib/mng.lib") 

#define STACK_MAXCAP 100000

#include ".\\gdiplus\\Include\\GdiPlus.h" 
using namespace Gdiplus;


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E5762F75_F518_492C_9043_2A0BBF77C4B3__INCLUDED_)
