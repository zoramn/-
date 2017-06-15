// ImageSegDoc.h : interface of the CImageSegDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGESEGDOC_H__054D7A5A_1895_4AC5_B6A5_E12F24DC6267__INCLUDED_)
#define AFX_IMAGESEGDOC_H__054D7A5A_1895_4AC5_B6A5_E12F24DC6267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using namespace std;

class CImageSegDoc : public CDocument
{
protected: // create from serialization only
	CImageSegDoc();
	DECLARE_DYNCREATE(CImageSegDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageSegDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	int sumGray;
	int pixNum;
	int m_growWay1;
	int m_growWay2;
	int m_growWay3;
	int m_growWay4;
	int m_howToGrow;
	void RegionGrow(CPoint pt);
	BOOL m_regionGrow;
	int nStackMax;
	int nWidth;
	int nHeight;
	
	//种子点
	int	nSeedX;
	int nSeedY;
	
	vector<CPoint>  m_stack;
	vector<vector<int> >  m_flag;//int 二维数组
	CxImage m_originBmp;
	CxImage m_showBmp;
	CView *pView;
	int m_threshold;
	int findMidGray(int a[]);
	BOOL CheckDot(int x,int y,int seedX,int seedY);
	BOOL AutoCheckDot(int x,int y,int seedX,int seedY);
	void Grow(int x,int y);
	void Grow2(int x,int y);
	virtual ~CImageSegDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageSegDoc)
	afx_msg void OnProSegRegiongrow();
	afx_msg void OnFileOpen();
	afx_msg void OnProSegOption();
	afx_msg void OnFileSaveAs();
	afx_msg void OnProReset();
	afx_msg void OnProSegWay1();
	afx_msg void OnUpdateProSegWay1(CCmdUI* pCmdUI);
	afx_msg void OnProSegWay2();
	afx_msg void OnUpdateProSegWay2(CCmdUI* pCmdUI);
	afx_msg void OnProSegWay3();
	afx_msg void OnUpdateProSegWay3(CCmdUI* pCmdUI);
	afx_msg void OnProSegWay4();
	afx_msg void OnUpdateProSegWay4(CCmdUI* pCmdUI);
	afx_msg void OnProSegOptionSpin();
	afx_msg void OnSegSmooth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGESEGDOC_H__054D7A5A_1895_4AC5_B6A5_E12F24DC6267__INCLUDED_)
