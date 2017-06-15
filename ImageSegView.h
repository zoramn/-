// ImageSegView.h : interface of the CImageSegView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGESEGVIEW_H__6AB3CAC7_5299_4E80_9E71_6F553E1754B2__INCLUDED_)
#define AFX_IMAGESEGVIEW_H__6AB3CAC7_5299_4E80_9E71_6F553E1754B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImageSegView : public CScrollView
{
protected: // create from serialization only
	CImageSegView();
	DECLARE_DYNCREATE(CImageSegView)

// Attributes
public:
	CImageSegDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageSegView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImageSegView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageSegView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImageSegView.cpp
inline CImageSegDoc* CImageSegView::GetDocument()
   { return (CImageSegDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGESEGVIEW_H__6AB3CAC7_5299_4E80_9E71_6F553E1754B2__INCLUDED_)
