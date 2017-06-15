// ImageSegDoc.cpp : implementation of the CImageSegDoc class
//

#include "stdafx.h"
#include "ImageSeg.h"

#include "GrowOptionDlg.h"
#include "ImageSegDoc.h"
#include "ImageSegView.h"
#include "SpinOptionDlg.h"


#include <highgui.h>

#ifdef _DEBUG
//#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageSegDoc

IMPLEMENT_DYNCREATE(CImageSegDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageSegDoc, CDocument)//响应消息函数
	//{{AFX_MSG_MAP(CImageSegDoc)
	ON_COMMAND(ID_PRO_SEG_REGIONGROW, OnProSegRegiongrow)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_PRO_SEG_OPTION, OnProSegOption)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_PRO_RESET, OnProReset)
	ON_COMMAND(ID_PRO_SEG_WAY_1, OnProSegWay1)
	ON_UPDATE_COMMAND_UI(ID_PRO_SEG_WAY_1, OnUpdateProSegWay1)
	ON_COMMAND(ID_PRO_SEG_WAY_2, OnProSegWay2)
	ON_UPDATE_COMMAND_UI(ID_PRO_SEG_WAY_2, OnUpdateProSegWay2)
	ON_COMMAND(ID_PRO_SEG_WAY_3, OnProSegWay3)
	ON_UPDATE_COMMAND_UI(ID_PRO_SEG_WAY_3, OnUpdateProSegWay3)
	ON_COMMAND(ID_PRO_SEG_WAY_4, OnProSegWay4)
	ON_UPDATE_COMMAND_UI(ID_PRO_SEG_WAY_4, OnUpdateProSegWay4)
	ON_COMMAND(ID_PRO_SEG_OPTION_SPIN, OnProSegOptionSpin)
	ON_COMMAND(ID_IMAGESEG_AUTO, OnSegSmooth)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageSegDoc construction/destruction

CImageSegDoc::CImageSegDoc()
{
	// TODO: add one-time construction code here//初始化变量值
	m_threshold=30;
	m_regionGrow=FALSE;
	m_growWay1=1;//采用的生长准测
	m_growWay2=0;
	m_growWay3=0;
	m_growWay4=0;
	m_howToGrow=1;
}

CImageSegDoc::~CImageSegDoc()
{
}

BOOL CImageSegDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImageSegDoc serialization

void CImageSegDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImageSegDoc diagnostics

#ifdef _DEBUG
void CImageSegDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageSegDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageSegDoc commands
//////////////////////////////////////////////////////////////////////////

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// return Image file type extraing from filename
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int GetTypeFromFileName(LPCTSTR pstr)//获得图像的类型
{
	CString fileName(pstr);
	CString ext3=fileName.Right(3);
	CString ext4=fileName.Right(4);//确定后缀是否为bmp
#if CXIMAGE_SUPPORT_BMP
	if(ext3.CompareNoCase(_T("bmp"))==0)
		return CXIMAGE_FORMAT_BMP;
#endif
#if CXIMAGE_SUPPORT_GIF
	if(ext3.CompareNoCase(_T("gif"))==0)
		return CXIMAGE_FORMAT_GIF;
#endif
#if CXIMAGE_SUPPORT_JPG
	if(ext3.CompareNoCase(_T("jpg"))==0 || ext4.CompareNoCase(_T("jpeg"))==0)
		return CXIMAGE_FORMAT_JPG;
#endif
#if CXIMAGE_SUPPORT_PNG
	if(ext3.CompareNoCase(_T("png"))==0)
		return CXIMAGE_FORMAT_PNG;
#endif
#if CXIMAGE_SUPPORT_MNG
	if(ext3.CompareNoCase(_T("mng"))==0 || ext3.CompareNoCase(_T("jng"))==0 ||ext3.CompareNoCase(_T("png"))==0)
		return CXIMAGE_FORMAT_MNG;
#endif
#if CXIMAGE_SUPPORT_ICO
	if(ext3.CompareNoCase(_T("ico"))==0)
		return CXIMAGE_FORMAT_ICO;
#endif
#if CXIMAGE_SUPPORT_TIF
	if(ext3.CompareNoCase(_T("tif"))==0 || ext4.CompareNoCase(_T("tiff"))==0)
		return CXIMAGE_FORMAT_TIF;
#endif
#if CXIMAGE_SUPPORT_TGA
	if(ext3.CompareNoCase(_T("tga"))==0)
		return CXIMAGE_FORMAT_TGA;
#endif
#if CXIMAGE_SUPPORT_PCX
	if(ext3.CompareNoCase(_T("pcx"))==0)
		return CXIMAGE_FORMAT_PCX;
#endif
#if CXIMAGE_SUPPORT_WBMP
	if(ext4.CompareNoCase(_T("wbmp"))==0)
		return CXIMAGE_FORMAT_WBMP;
#endif
#if CXIMAGE_SUPPORT_WMF
	if(ext3.CompareNoCase(_T("wmf"))==0 || ext3.CompareNoCase(_T("emf"))==0)
		return CXIMAGE_FORMAT_WMF;
#endif
#if CXIMAGE_SUPPORT_J2K
	if(ext3.CompareNoCase(_T("j2k"))==0 || ext3.CompareNoCase(_T("jp2"))==0)
		return CXIMAGE_FORMAT_J2K;
#endif
#if CXIMAGE_SUPPORT_JBG
	if(ext3.CompareNoCase(_T("jbg"))==0)
		return CXIMAGE_FORMAT_JBG;
#endif
#if CXIMAGE_SUPPORT_JP2
	if(ext3.CompareNoCase(_T("j2k"))==0 || ext3.CompareNoCase(_T("jp2"))==0)
		return CXIMAGE_FORMAT_JP2;
#endif
#if CXIMAGE_SUPPORT_JPC
	if(ext3.CompareNoCase(_T("j2c"))==0 || ext3.CompareNoCase(_T("jpc"))==0)
		return CXIMAGE_FORMAT_JPC;
#endif
#if CXIMAGE_SUPPORT_PGX
	if(ext3.CompareNoCase(_T("pgx"))==0)
		return CXIMAGE_FORMAT_PGX;
#endif
#if CXIMAGE_SUPPORT_PNM
	if(ext3.CompareNoCase(_T("pnm"))==0 || ext3.CompareNoCase(_T("pgm"))==0 || ext3.CompareNoCase(_T("ppm"))==0)
		return CXIMAGE_FORMAT_PNM;
#endif

#if CXIMAGE_SUPPORT_RAS
	if(ext3.CompareNoCase(_T("ras"))==0)
		return CXIMAGE_FORMAT_RAS;
#endif

	return CXIMAGE_FORMAT_UNKNOWN;
}

void CImageSegDoc::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	
	static CString szFilter1="BMP - Windows位图(*.bmp)|*.bmp|";
	szFilter1+="JPG - JPEG JFIF(*.jpg)|*.jpg|";
	szFilter1+="PNG - 便携网络图像(*.png)|*.png|";
	szFilter1+="JPC (*.jpc)|*.jpc|";
	szFilter1+="TIFF - 标记图像文件(*.tif)|*.tif|";
	szFilter1+="JP2 - JPEG2000 JP2文件(*.jp2)|*.jp2|";
	szFilter1+="EMF - 增强型元文件(*.emf)|*.emf|";
	szFilter1+="PCX - ZSoft 发布程序画笔(*.pcx)|*.pcx|";
	szFilter1+="TGA - Targa TGA(*.tga)|*.tga|";
	szFilter1+="WBMP - 无线BMP文件(*.wbmp)|*.wbmp|";
	szFilter1+="WMF (*.wmf)|*.wmf|";
	szFilter1+="所有类型 (*.*)|*.*||";

	CFileDialog m_ldFile(FALSE,"bmp",NULL,OFN_HIDEREADONLY
		|OFN_NONETWORKBUTTON|OFN_PATHMUSTEXIST|OFN_OVERWRITEPROMPT,szFilter1); 
	if(m_ldFile.DoModal() == IDOK)
	{
		char filename[MAX_PATH];
		strcpy(filename,m_ldFile.GetPathName().GetBuffer(MAX_PATH));

		m_showBmp.Save(filename,GetTypeFromFileName(filename));
	}
}

void CImageSegDoc::OnFileOpen() //打开图片（各种类型）
{
	// TODO: Add your command handler code here
		
	static CString szFilter2="BMP - Windows位图(*.bmp)|*.bmp|";
	szFilter2+="JPG - JPEG JFIF(*.jpg)|*.jpg|";
	szFilter2+="PNG - 便携网络图像(*.png)|*.png|";
	szFilter2+="JPC (*.jpc)|*.jpc|";
	szFilter2+="TIFF - 标记图像文件(*.tif)|*.tif|";
	szFilter2+="JP2 - JPEG2000 JP2文件(*.jp2)|*.jp2|";
	szFilter2+="EMF - 增强型元文件(*.emf)|*.emf|";
	szFilter2+="PCX - ZSoft 发布程序画笔(*.pcx)|*.pcx|";
	szFilter2+="TGA - Targa TGA(*.tga)|*.tga|";
	szFilter2+="WBMP - 无线BMP文件(*.wbmp)|*.wbmp|";
	szFilter2+="WMF (*.wmf)|*.wmf|";
	szFilter2+="所有类型 (*.*)|*.*||";

	CFileDialog m_ldFile(TRUE,"bmp",NULL,OFN_HIDEREADONLY
		|OFN_NONETWORKBUTTON|OFN_PATHMUSTEXIST|OFN_OVERWRITEPROMPT,szFilter2); 
	//////new add
	m_ldFile.m_ofn.lpstrTitle=_T("Open Image");
	/////////////////////
	if(m_ldFile.DoModal() == IDOK)
	{
	
		CString path=m_ldFile.GetPathName();
    	IplImage* img=cvLoadImage(path);



		SetTitle(m_ldFile.GetFileTitle());
		m_originBmp.Load(m_ldFile.GetPathName().GetBuffer(MAX_PATH));
		m_showBmp.Copy(m_originBmp);
		
		//绘制  强制调用ONDRAW()函数
		((CImageSegView *)pView)->Invalidate();
		
		
		//图像宽高
		nWidth=m_originBmp.GetWidth();
		nHeight=m_originBmp.GetHeight();

		//种子点
		nSeedX=m_originBmp.GetWidth()/2;//初始化设定的种子像素点
		nSeedY=m_originBmp.GetHeight()/2;

		///////////////////获得种子点
	}
}

void CImageSegDoc::OnProSegRegiongrow() 
{
	// TODO: Add your command handler code here

	m_regionGrow=TRUE;
  
}

/*
void CImageSegDoc::RegionGrow(CPoint pt)
{
	nSeedX=pt.x;
	nSeedY=m_originBmp.GetHeight()-pt.y;

	if (!m_originBmp.IsValid())
	{
		return;
	}

	CxImage img;
	CxImage img2;
	img.Copy(m_originBmp);
	img2.Copy(m_originBmp);


//////////////////////////////////////////////////////////////////////////
// 处理左半部
//////////////////////////////////////////////////////////////////////////
	
	m_flag.empty();

	m_flag.resize(m_originBmp.GetWidth());
	for(int i=0;i<m_originBmp.GetWidth();i++)
	{
		m_flag[i].resize(m_originBmp.GetHeight());
	}

	for(int m=0;m<m_originBmp.GetWidth();m++)
	{
		for(int n=0;n<m_originBmp.GetHeight();n++)
		{
			m_flag[m][n]=-1;
		}
	}

	//递归深度变量
	nStackMax=0;

	Grow(nSeedX, nSeedY);
	
	for(m=0;m<img.GetWidth();m++)
	{
		for(int n=0;n<img.GetHeight();n++)
		{
			if(m_flag[m][n]==0) img.SetPixelColor(m,n,RGB(0,0,0));
			else img.SetPixelColor(m,n,RGB(255,255,255));
		}
	}
	

//////////////////////////////////////////////////////////////////////////
// 处理右半部
//////////////////////////////////////////////////////////////////////////

	m_flag.empty();

	m_flag.resize(m_originBmp.GetWidth());
	for(i=0;i<m_originBmp.GetWidth();i++)
	{
		m_flag[i].resize(m_originBmp.GetHeight());
	}

	for(m=0;m<m_originBmp.GetWidth();m++)
	{
		for(int n=0;n<m_originBmp.GetHeight();n++)
		{
			m_flag[m][n]=-1;
		}
	}

	//递归深度变量
	nStackMax=0;

	Grow2(nSeedX, nSeedY);
	
	for(m=0;m<img2.GetWidth();m++)
	{
		for(int n=0;n<img2.GetHeight();n++)
		{
			if(m_flag[m][n]==0) img2.SetPixelColor(m,n,RGB(0,0,0));
			else img2.SetPixelColor(m,n,RGB(255,255,255));
		}
	}


//////////////////////////////////////////////////////////////////////////
// 合成
//////////////////////////////////////////////////////////////////////////
	m_showBmp.Copy(img);
	m_showBmp.Mix(img2,CxImage::OpMask);


	//绘制
	((CImageSegView *)pView)->Invalidate();

}

void CImageSegDoc::Grow(int x, int y)
{
	nStackMax++;
	
	if(m_flag[x][y]==0)
	{
		nStackMax--;
		return;
	}

	//递归深度限制
	if(nStackMax>STACK_MAXCAP){
		nStackMax--;
		return;
	}

	if(CheckDot(x,y,nSeedX,nSeedY)){
		m_flag[x][y]=0;
	if(x>=1){
//		nSeedX=x;
//		nSeedY=y;
		Grow(x-1,y);
	}
	if(y<=nHeight-2){
//		nSeedX=x;
//		nSeedY=y;
		Grow(x,y+1);
	}
	if(y>=1){
//		nSeedX=x;
//		nSeedY=y;
		Grow(x,y-1);
	}
	}	
	else{		
		m_flag[x][y]=1;
	}			
	

	nStackMax--;
}

void CImageSegDoc::Grow2(int x, int y)
{
	nStackMax++;
	
	if(m_flag[x][y]==0)
	{
		nStackMax--;
		return;
	}

	//递归深度限制
	if(nStackMax>STACK_MAXCAP){
		nStackMax--;
		return;
	}

	if(CheckDot(x,y,nSeedX,nSeedY)){
		m_flag[x][y]=0;	
	if(x<=nWidth-2){
//		nSeedX=x;
//		nSeedY=y;
		Grow2(x+1,y);
	}
	if(y<=nHeight-2){
//		nSeedX=x;
//		nSeedY=y;
		Grow2(x,y+1);
	}
	if(y>=1){
//		nSeedX=x;
//		nSeedY=y;
		Grow2(x,y-1);
	}
	}	
	else{		
		m_flag[x][y]=1;
	}	
	
		
	nStackMax--;
}
*/
void CImageSegDoc::RegionGrow(CPoint pt)
{	
	if (!m_originBmp.IsValid())
	{
		return;
	}

	static int nDx[]={-1,0,1,0};
	static int nDy[]={0,1,0,-1};

	//计算种子点坐标
	nSeedX=pt.x;
	nSeedY=pt.y;

	//堆栈初始化
	m_flag.empty();
	m_flag.resize(m_originBmp.GetWidth());
	for(int i=0;i<m_originBmp.GetWidth();i++)
	{
		m_flag[i].resize(m_originBmp.GetHeight());
	}

	for(int m=0;m<m_originBmp.GetWidth();m++)
	{
		for(int n=0;n<m_originBmp.GetHeight();n++)
		{
			m_flag[m][n]=-1; //表示未处理
		}
	}
	m_stack.empty();
	//m_stack.resize(0);

	//初始种子点入队列
	m_stack.insert(m_stack.begin(),CPoint(nSeedX,nSeedY));
	
	//当前灰度和,当前像素数
	sumGray=m_originBmp.GetPixelGray(nSeedX,nSeedY);
	pixNum=1;

	//当前处理像素
	int nCurrX;
	int nCurrY;

	while(m_stack.size())
	{
		//从队列中得到当前种子点
		CPoint ptCurr=m_stack.back();
		m_stack.pop_back(); 
		nCurrX=ptCurr.x;
		nCurrY=ptCurr.y;

		//遍历4邻域
		for(int k=0;k<4;k++)
		{
			//4邻域像素
			int xx=nCurrX+nDx[k];
			int yy=nCurrY+nDy[k];

			if(CheckDot(xx,yy,nCurrX,nCurrY))
			{
				//放入队列
				m_stack.insert(m_stack.begin(),CPoint(xx,yy));

				//修改处理标志
				m_flag[xx][yy]=0;

				//
				pixNum++;
				sumGray+=m_originBmp.GetPixelGray(xx,yy);
			}
		}
	}

	//处理图像
	CxImage img;
	img.Copy(m_originBmp);

	for(m=0;m<img.GetWidth();m++)
	{
		for(int n=0;n<img.GetHeight();n++)
		{
			if(m_flag[m][n]!=0) //img.SetPixelColor(m,n,RGB(0,0,0));
				{ img.SetPixelColor(m,n,RGB(255,255,255));}
		}
	}

	//绘制图像
	m_showBmp.Copy(img);
	((CImageSegView *)pView)->Invalidate();

}
////////////////////////////////////////////////////////////////

void CImageSegDoc::OnSegSmooth()
{
	if (!m_originBmp.IsValid())
	{
		return;
	}

	static int nDx[]={-1,-1,-1,0,1,1,1,0};
	static int nDy[]={-1,0,1,1,1,0,-1,-1};
	int LSeedX,LSeedY,RSeedX,RSeedY;
	//计算种子点坐标
	//首先固定每个图片像素
	//////////////////
	//思考一个问题，当遍历后坐标为空该如何处置NULL
	int wei=m_originBmp.GetWidth();
	int len=m_originBmp.GetHeight();
	int flag=0;
	for(int r=413;r>=89;r--)
	{
			int temp=m_originBmp.GetPixelGray(r,357);
	    	if(temp>50 && temp<100)
			{
			LSeedX=r;
			LSeedY=357;
			flag=1;
			break;
			}
	}
			if(flag==1) {
				m_stack.insert(m_stack.begin(),CPoint(LSeedX,LSeedY));}

/*	for(r=270;r>=30;r--)
	{
	    	flag=0;
     		int temp=m_originBmp.GetPixelGray(r,134);
	    	if(temp>50 && temp<100)
			{
			RSeedX=r;
			RSeedY=134;
			flag=1;
			break;
			}
	}
			if(flag==1) {
				m_stack.insert(m_stack.begin(),CPoint(RSeedX,RSeedY));}
*/
	for(r=len/2-20;r<len/2+20;r++)
	{
		flag=0;
		for(int l=30;l<wei/2;l++)
		{
	    	int temp=m_originBmp.GetPixelGray(l,len-r);
	    	if(temp>50 && temp<100)
			{
			LSeedX=l;
			LSeedY=len-r;
			flag=1;
			break;
			}
		}
		if(flag==1) {
			m_stack.insert(m_stack.begin(),CPoint(LSeedX,LSeedY));
		//	m_originBmp.SetPixelColor(LSeedX,LSeedY,RGB(255,0,255));
		}
	}
	for(r=len/2-20;r<len/2+20;r++)
	{
		flag=0;
		for(int l=470;l>wei/2;l--)
		{
	    	int temp=m_originBmp.GetPixelGray(l,len-r);
	    	if(temp>50 && temp<100)
			{
			RSeedX=l;
			RSeedY=len-r;
			flag=1;
			break;
			}
		}
		if(flag==1) {
			m_stack.insert(m_stack.begin(),CPoint(RSeedX,RSeedY));
		  //  m_originBmp.SetPixelColor(RSeedX,RSeedY,RGB(255,0,255));
		}
	}
   // m_showBmp.Copy(m_originBmp);
//	((CImageSegView *)pView)->Invalidate();

	//堆栈初始化
	m_flag.empty();
	m_flag.resize(m_originBmp.GetWidth());
	for(int i=0;i<m_originBmp.GetWidth();i++)
	{
		m_flag[i].resize(m_originBmp.GetHeight());
	}

	for(int m=0;m<m_originBmp.GetWidth();m++)
	{
		for(int n=0;n<m_originBmp.GetHeight();n++)
		{
			m_flag[m][n]=-1; //表示未处理
		}
	}
	m_stack.empty();

	//初始种子点入队列
	m_stack.insert(m_stack.begin(),CPoint(RSeedX,RSeedY));
	m_stack.insert(m_stack.begin(),CPoint(LSeedX,LSeedY));

	
	//当前灰度和,当前像素数
	sumGray=m_originBmp.GetPixelGray(RSeedX,RSeedY);
	pixNum=1;

	//当前处理像素
	int nCurrX;
	int nCurrY;

	while(m_stack.size())
	{
		//从队列中得到当前种子点
		CPoint ptCurr=m_stack.back();
		m_stack.pop_back(); 
		nCurrX=ptCurr.x;
		nCurrY=ptCurr.y;

		//遍历8邻域
		for(int k=0;k<8;k++)
		{
			//8邻域像素
			int xx=nCurrX+nDx[k];
			int yy=nCurrY+nDy[k];

			if(AutoCheckDot(xx,yy,nCurrX,nCurrY))
			{
				//放入队列
				m_stack.insert(m_stack.begin(),CPoint(xx,yy));

				//修改处理标志
				m_flag[xx][yy]=0;

				//
				pixNum++;
				sumGray+=m_originBmp.GetPixelGray(xx,yy);
			}
		}
	}

	//处理图像
	CxImage img;
	img.Copy(m_originBmp);

	for(m=0;m<img.GetWidth();m++)
	{
		for(int n=0;n<img.GetHeight();n++)
		{
			if(m_flag[m][n]!=0) //img.SetPixelColor(m,n,RGB(0,0,0));
				{ img.SetPixelColor(m,n,RGB(255,255,255));}
		}
	}

	//绘制图像
	m_showBmp.Copy(img);
	((CImageSegView *)pView)->Invalidate();
}

BOOL CImageSegDoc::AutoCheckDot(int x, int y,int seedX,int seedY)
{
	if(x<0||x>m_originBmp.GetWidth()-1||y<0||y>m_originBmp.GetHeight()-1) return FALSE;
	
	//检查是否处理过
	if(m_flag[x][y]!=-1) return FALSE;
	
	int grayValue=m_originBmp.GetPixelGray(x,y);
	int grayValueSeed=m_originBmp.GetPixelGray(seedX,seedY);
	int grayValueAve=sumGray/pixNum;
	if(abs(grayValue-grayValueAve)<=30)
		{
			return TRUE;
		}
		else return FALSE;
}


BOOL CImageSegDoc::CheckDot(int x, int y,int seedX,int seedY)
{
	//检验是否超出图像范围
	if(x<0||x>m_originBmp.GetWidth()-1||y<0||y>m_originBmp.GetHeight()-1) return FALSE;
	
	//检查是否处理过
	if(m_flag[x][y]!=-1) return FALSE;
	
	int grayValueOSeed=m_originBmp.GetPixelGray(nSeedX,nSeedY);
	int grayValue=m_originBmp.GetPixelGray(x,y);
	int grayValueSeed=m_originBmp.GetPixelGray(seedX,seedY);
	int grayValueAve=sumGray/pixNum;

	switch(m_howToGrow) {
	case 1:
		if(abs(grayValue-grayValueSeed)<=m_threshold)
		{
			return TRUE;
		}
		else return FALSE;

		break;

	case 2:
		if(abs(grayValue-grayValueOSeed)<=m_threshold)
		{
			return TRUE;
		}
		else return FALSE;
		
		break;

	case 3:
		if(abs(grayValue-grayValueAve)<=m_threshold)
		{
			return TRUE;
		}
		else return FALSE;

		break;

	case 4:
		if(abs(((grayValue-grayValueAve)*100)/grayValueAve)<=m_threshold)
		{
			return TRUE;
		}
		else return FALSE;

		break;

	default:
		return FALSE;
	}
}

void CImageSegDoc::OnProSegOption() 
{
	// TODO: Add your command handler code here

	GrowOptionDlg dlg;

	dlg.m_threhold=m_threshold;

	if(dlg.DoModal()==IDOK){
		m_threshold=dlg.m_threhold;
	}
}

void CImageSegDoc::OnProSegOptionSpin() 
{
	// TODO: Add your command handler code here
	
	SpinOptionDlg dlg;

	dlg.m_threhold=m_threshold;
	dlg.pDoc=this;

	dlg.DoModal();
}


void CImageSegDoc::OnProReset() 
{
	// TODO: Add your command handler code here
	
	//绘制图像
	m_showBmp.Copy(m_originBmp);
	((CImageSegView *)pView)->Invalidate();
}

void CImageSegDoc::OnProSegWay1() 
{
	// TODO: Add your command handler code here
	
	m_growWay1=1;
	m_growWay2=0;
	m_growWay3=0;
	m_growWay4=0;

	m_howToGrow=1;
}

void CImageSegDoc::OnUpdateProSegWay1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here

	pCmdUI->SetCheck(m_growWay1);	
}

void CImageSegDoc::OnProSegWay2() 
{
	// TODO: Add your command handler code here
	
	m_growWay1=0;
	m_growWay2=1;
	m_growWay3=0;
	m_growWay4=0;

	m_howToGrow=2;
}

void CImageSegDoc::OnUpdateProSegWay2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here

	pCmdUI->SetCheck(m_growWay2);
}

void CImageSegDoc::OnProSegWay3() 
{
	// TODO: Add your command handler code here
	
	m_growWay1=0;
	m_growWay2=0;
	m_growWay3=1;
	m_growWay4=0;

	m_howToGrow=3;
}

void CImageSegDoc::OnUpdateProSegWay3(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	pCmdUI->SetCheck(m_growWay3);
}

void CImageSegDoc::OnProSegWay4() 
{
	// TODO: Add your command handler code here
	
	m_growWay1=0;
	m_growWay2=0;
	m_growWay3=0;
	m_growWay4=1;

	m_howToGrow=4;
}

void CImageSegDoc::OnUpdateProSegWay4(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
	pCmdUI->SetCheck(m_growWay4);
}
