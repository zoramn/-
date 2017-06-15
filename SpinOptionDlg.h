#if !defined(AFX_SPINOPTIONDLG_H__771FE22E_562C_4878_828E_1231DA9F53FF__INCLUDED_)
#define AFX_SPINOPTIONDLG_H__771FE22E_562C_4878_828E_1231DA9F53FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpinOptionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SpinOptionDlg dialog

class SpinOptionDlg : public CDialog
{
// Construction
public:
	CDocument *pDoc;
	SpinOptionDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SpinOptionDlg)
	enum { IDD = IDD_DIALOG_GROWOPTION_SPIN };
	int		m_threhold;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SpinOptionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SpinOptionDlg)
	afx_msg void OnChangeEditThrehold();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPINOPTIONDLG_H__771FE22E_562C_4878_828E_1231DA9F53FF__INCLUDED_)
