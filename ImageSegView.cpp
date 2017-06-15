// ImageSegView.cpp : implementation of the CImageSegView class
//

#include "stdafx.h"
#include "ImageSeg.h"

#include "ImageSegDoc.h"
#include "ImageSegView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageSegView

IMPLEMENT_DYNCREATE(CImageSegView, CScrollView)

BEGIN_MESSAGE_MAP(CImageSegView, CScrollView)
	//{{AFX_MSG_MAP(CImageSegView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageSegView construction/destruction

CImageSegView::CImageSegView()
{
	// TODO: add construction code here

}

CImageSegView::~CImageSegView()
{
}

BOOL CImageSegView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImageSegView drawing

void CImageSegView::OnDraw(CDC* pDC)
{
	CImageSegDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	if (pDoc->m_showBmp.IsValid())
	{
		pDoc->m_showBmp.Draw(pDC->m_hDC,CRect(0,0,pDoc->m_originBmp.GetWidth(),pDoc->m_originBmp.GetHeight()));
			
		//确定滚动条范围
		CSize cs;		
		if(	pDoc->m_showBmp.GetWidth()<800) cs.cx=0;
		else cs.cx=	pDoc->m_showBmp.GetWidth();
		if(	pDoc->m_showBmp.GetHeight()<550) cs.cy=0;
		else cs.cy=	pDoc->m_showBmp.GetHeight();
		SetScrollSizes(MM_TEXT,cs);
	}
}

void CImageSegView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);

	//
	CImageSegDoc* pDoc = GetDocument();
	pDoc->pView=this;

}

/////////////////////////////////////////////////////////////////////////////
// CImageSegView printing

BOOL CImageSegView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageSegView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageSegView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImageSegView diagnostics

#ifdef _DEBUG
void CImageSegView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CImageSegView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CImageSegDoc* CImageSegView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageSegDoc)));
	return (CImageSegDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageSegView message handlers

void CImageSegView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CImageSegDoc* pDoc = GetDocument();

	if(pDoc->m_regionGrow)
	{
		//获得焦点
		SetCapture();
		
		//改变鼠标形态
		::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR_SUCK));
	}
	CScrollView::OnMouseMove(nFlags, point);
}

void CImageSegView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
 	CImageSegDoc* pDoc = GetDocument();
 
 	if(pDoc->m_regionGrow)//可以分割
 	{
		int x=point.x;
		int y=pDoc->m_originBmp.GetHeight()-point.y;//由于坐标是相反方向的。

 		pDoc->RegionGrow(CPoint(x,y));
 		pDoc->m_regionGrow=FALSE;
 		
 		//释放焦点
 		ReleaseCapture();
 	}
	
	CScrollView::OnLButtonUp(nFlags, point);
}
