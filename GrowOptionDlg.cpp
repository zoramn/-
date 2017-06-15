// GrowOptionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageSeg.h"
#include "GrowOptionDlg.h"
#include "ImageSegDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GrowOptionDlg dialog


GrowOptionDlg::GrowOptionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(GrowOptionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(GrowOptionDlg)
	m_threhold = 0;
	//}}AFX_DATA_INIT
}


void GrowOptionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GrowOptionDlg)
	DDX_Text(pDX, IDC_EDIT_THREHOLD, m_threhold);
	DDV_MinMaxInt(pDX, m_threhold, 0, 50);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GrowOptionDlg, CDialog)
	//{{AFX_MSG_MAP(GrowOptionDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GrowOptionDlg message handlers


