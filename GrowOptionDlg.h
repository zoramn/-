#if !defined(AFX_GROWOPTIONDLG_H__09470BD3_AFA3_4D2B_8017_8988E90F79C7__INCLUDED_)
#define AFX_GROWOPTIONDLG_H__09470BD3_AFA3_4D2B_8017_8988E90F79C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GrowOptionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GrowOptionDlg dialog

class GrowOptionDlg : public CDialog
{
// Construction
public:
	GrowOptionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(GrowOptionDlg)
	enum { IDD = IDD_DIALOG_GROWOPTION };
	int		m_threhold;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GrowOptionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GrowOptionDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROWOPTIONDLG_H__09470BD3_AFA3_4D2B_8017_8988E90F79C7__INCLUDED_)
