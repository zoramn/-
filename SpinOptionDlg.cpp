// SpinOptionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageSeg.h"
#include "SpinOptionDlg.h"
#include "ImageSegDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SpinOptionDlg dialog


SpinOptionDlg::SpinOptionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(SpinOptionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(SpinOptionDlg)
	m_threhold = 0;
	//}}AFX_DATA_INIT
}


void SpinOptionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SpinOptionDlg)
	DDX_Text(pDX, IDC_EDIT_THREHOLD, m_threhold);
	DDV_MinMaxInt(pDX, m_threhold, 0, 50);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SpinOptionDlg, CDialog)
	//{{AFX_MSG_MAP(SpinOptionDlg)
	ON_EN_CHANGE(IDC_EDIT_THREHOLD, OnChangeEditThrehold)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SpinOptionDlg message handlers

void SpinOptionDlg::OnChangeEditThrehold() //ÐÞ¸ÄãÐÖµ
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
	UpdateData();
	
	((CImageSegDoc *)pDoc)->m_threshold=m_threhold;

	((CImageSegDoc *)pDoc)->RegionGrow(CPoint(((CImageSegDoc *)pDoc)->nSeedX,((CImageSegDoc *)pDoc)->nSeedY));

}
