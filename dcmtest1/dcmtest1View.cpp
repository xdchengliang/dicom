
// dcmtest1View.cpp : Cdcmtest1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "dcmtest1.h"
#endif

#include "dcmtest1Doc.h"
#include "dcmtest1View.h"
#include "TagInfoDialog.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include <Windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cdcmtest1View

IMPLEMENT_DYNCREATE(Cdcmtest1View, CView)

BEGIN_MESSAGE_MAP(Cdcmtest1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_SHOW_TAG , OnShowTag)
	ON_UPDATE_COMMAND_UI(ID_SHOW_TAG , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_WCWW_FULL , OnUpdateTagMenu)
	ON_UPDATE_COMMAND_UI(ID_WCWW_Default , OnUpdateTagMenu)
	ON_COMMAND(ID_WCWW_Default , OnUpdateDefaultWCWW)
	ON_COMMAND(ID_WCWW_FULL , OnUpdateFullWCWW)
//	ON_WM_ERASEBKGND()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cdcmtest1View ����/����

Cdcmtest1View::Cdcmtest1View()
	: dcm(NULL),
	pDicomFile(NULL),
	pDataset(NULL),
	m_bShowTagEnable(false),
	m_destX(0),
	m_destY(0),
	m_destWidth(0),
	m_destHeight(0),
	m_pixelX(0),
	m_pixelY(0),
	m_pixelValue(0),
	isResetWindow(false)
{
	// TODO: �ڴ˴���ӹ������
	//AllocConsole();                     // �򿪿���̨��Դ

	//freopen( "CONOUT$", "w+t", stdout );// ����д
	//freopen( "CONIN$", "r+t", stdin );  // �����
}

Cdcmtest1View::~Cdcmtest1View()
{
	//FreeConsole();                      // �ͷſ���̨��Դ
}

BOOL Cdcmtest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cdcmtest1View ����

void Cdcmtest1View::OnDraw(CDC* pDC)
{

	Cdcmtest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
// 	SB_BitmapInfoHeader infoHeader;
// 	infoHeader.biSize = sizeof(SB_BitmapInfoHeader);
// 	infoHeader.biWidth = pDoc->dcm->getHeight();
// 	infoHeader.biHeight = pDoc->dcm->getWidth();
// 	infoHeader.biPlanes = 1;
// 	infoHeader.biBitCount = 
	//dcm =  new DicomImage(pDoc->strPicPath,0,0,0);
	//pDicomFile = new DcmFileFormat();
	//pDicomFile->loadFile("D:\\Guo_Yu\\Project\\dcmdata\\AELQYFNH\\I1000000");
	//pDataset = pDicomFile->getDataset();
	//E_TransferSyntax xfer=pDataset->getOriginalXfer();
	//dcm = new DicomImage(pDataset,xfer);
	/*DicomImage* temp*/
	//dcm = new DicomImage("D:\\Guo_Yu\\Project\\dcmdata\\\layer8\\IM8",CIF_UseAbsolutePixelRange,0,0);

	//dcm = tempdcm->createClippedImage(100,100,tempdcm->getWidth()-200,tempdcm->getHeight()-200);
	//Uint32 size = dcm->getOutputDataSize();
	//Uint8 *pixelData = (Uint8 *)(dcm->getOutputData(8 /* bits per sample */));
 //   if (pixelData != NULL)
 //   {
 //     /* do something useful with the pixel data */
 //   }

	//for(int i=0; i<size; i++)
	//{
	//	if(pixelData[i]!=128)
	//	{
	//		pixelData[i];
	//	}
	//}

	//Set the view background color
	CBrush   backBrush(RGB(0, 0,0));
              //   �����ˢ��  
    pDC->SelectObject(&backBrush);  
    CRect   rect;
	GetClientRect(&rect);
    //pDC->GetClipBox(&rect);           //   �������������  
    pDC->PatBlt(rect.left,rect.top,rect.Width(),rect.Height(),PATCOPY); 

	if(pDoc->dcm != NULL)
	{		
		//CRect rect;
		//GetClientRect(&rect);
		m_destHeight = rect.Height();
		m_destWidth = pDoc->m_lpBMIH->biWidth*m_destHeight/pDoc->m_lpBMIH->biHeight;
		m_destX = (rect.Width() - m_destWidth)/2;
		m_destY = 0;


		StretchDIBits(pDC->GetSafeHdc(),m_destX,m_destY,m_destWidth,
			m_destHeight,0,0,pDoc->m_lpBMIH->biWidth,
			pDoc->m_lpBMIH->biHeight,pDoc->pDicomDibits,
			(LPBITMAPINFO)pDoc->m_lpBMIH,DIB_PAL_COLORS,SRCCOPY);
		m_bShowTagEnable = true;
		
		//UpdateLabelText();
		UpdateLabelText(pDC);
	}

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void Cdcmtest1View::OnShowTag()
{	
	Cdcmtest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || !pDoc->dcm)
		return;
	TagInfoDialog tagDlg(pDoc->pDataset);
	tagDlg.DoModal();
	//AfxMessageBox("Show Tag");
}

void Cdcmtest1View::OnUpdateTagMenu(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(m_bShowTagEnable);
}


void Cdcmtest1View::OnUpdateDefaultWCWW()
{
	Cdcmtest1Doc* pDoc = GetDocument();
	OFString wc,ww;
	if (pDoc->pDataset->findAndGetOFString(DCM_WC, wc).good()&&
		pDoc->pDataset->findAndGetOFString(DCM_WW, ww).good())
	{
		pDoc->m_curWC = atof(wc.c_str());
		pDoc->m_curWW = atof(ww.c_str());
		pDoc->dcm->setWindow(pDoc->m_curWC,pDoc->m_curWW);
	}
	
		
	if(pDoc->pDicomDibits!=NULL)
		delete[]pDoc->pDicomDibits;
	int size = pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
		
	if( size == 0)
	{
		AfxMessageBox("Create DIB failed!");
	}
		
	Invalidate();
}

void Cdcmtest1View::OnUpdateFullWCWW()
{
	Cdcmtest1Doc* pDoc = GetDocument();
	double min,max;
	pDoc->dcm->getMinMaxValues(min,max);
	pDoc->m_curWW = (max-min)/2;
	pDoc->m_curWC = (max+min)/2;
	pDoc->dcm->setWindow(pDoc->m_curWC,pDoc->m_curWW);

	if(pDoc->pDicomDibits!=NULL)
		delete[]pDoc->pDicomDibits;
	int size = pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
		
	if( size == 0)
	{
		AfxMessageBox("Create DIB failed!");
	}
		
	Invalidate();
}

// Cdcmtest1View ���

#ifdef _DEBUG
void Cdcmtest1View::AssertValid() const
{
	CView::AssertValid();
}

void Cdcmtest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdcmtest1Doc* Cdcmtest1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdcmtest1Doc)));
	return (Cdcmtest1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cdcmtest1View ��Ϣ�������

void Cdcmtest1View::UpdateLabelText(CDC* pDC)
{	
	Cdcmtest1Doc* pDoc = GetDocument();

	int txt_width = 240;
	int txt_height = 20;
    CRect   rect;
    GetClientRect(&rect);
	int view_width = rect.Width();
	int view_height = rect.Height();

	pDC->SetTextColor(RGB(255,255,255));
	pDC->SetBkMode(TRANSPARENT);
	
	OFString tempstring;
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientName, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 0, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientID, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientBirth, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 2*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientSex, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width/6, 2*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_Institution, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 3*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PPSID, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 4*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_StudyDes, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 5*txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_SeriesDes, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, 6*txt_height, tempstring.data());
	}

	char wc_ww[10];
	itoa(pDoc->m_curWC, wc_ww, 10);
	pDC->TextOutA(0, view_height-txt_height, wc_ww);

	itoa(pDoc->m_curWW, wc_ww, 10);
	pDC->TextOutA(txt_width/2, view_height-txt_height, wc_ww);

	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_CtnDate, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width, view_height-txt_height, tempstring.data());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_CtnTime, tempstring).good())
	{
		pDC->TextOutA(view_width-txt_width/2, view_height-txt_height, tempstring.data());
	}
		
	if(m_pixelX!=0&&m_pixelY!=0)
	{
		CString value;
		value.Format("X:%d Y:%d value:%d",m_pixelX,m_pixelY,m_pixelValue);
		pDC->TextOutA(0, view_height-2*txt_height,value);
	}

}

//BOOL Cdcmtest1View::OnEraseBkgnd(CDC* pDC)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CBrush   backBrush(RGB(0, 0,0));
//              //   �����ˢ��  
//    pDC->SelectObject(&backBrush);  
//    CRect   rect;  
//    pDC->GetClipBox(&rect);           //   �������������  
//    pDC->PatBlt(rect.left,rect.top,rect.Width(),rect.Height(),PATCOPY);  
//    //pDC->SelectObject(pOldBrush);
//
//	return CView::OnEraseBkgnd(pDC);
//}


void Cdcmtest1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);

	m_startPoint.x = point.x;
	m_startPoint.y = point.y;
	m_curPoint.x = point.x;
	m_curPoint.y = point.y;
	printf("m_startPoint.x = %d, m_startPoint.y = %d \r\n",m_startPoint.x, m_startPoint.y);
	isResetWindow = true;
}


void Cdcmtest1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags, point);

	isResetWindow = false;
}


void Cdcmtest1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnMouseMove(nFlags, point);
	Cdcmtest1Doc* pDoc = GetDocument();
	
	int txt_width = 240;
	int txt_height = 20;
	CRect   rect;
	GetClientRect(&rect);
	int view_width = rect.Width();
	int view_height = rect.Height();

	if(pDoc->dcm!=NULL)
	{
		if (isResetWindow) 
		{
			if(abs(point.x-m_curPoint.x)+abs(point.y-m_curPoint.y)>10)
			{
				printf("m_curPoint.x = %d, m_curPoint.y = %d \r\n",m_curPoint.x, m_curPoint.y);
				printf("point.x = %d, point.y = %d \r\n",point.x, point.y);
				pDoc->m_curWC=pDoc->m_curWC+(-point.x+m_curPoint.x);
				pDoc->m_curWW=pDoc->m_curWW+(point.y-m_curPoint.y);
				m_curPoint.x=point.x;
				m_curPoint.y=point.y;
				if(pDoc->m_curWC>2047)
					pDoc->m_curWC=2047;
				if(pDoc->m_curWC<-2048)
					pDoc->m_curWC=-2048;
				if(pDoc->m_curWW>2047)
					pDoc->m_curWW=2047;
				if(pDoc->m_curWW<-2048)
					pDoc->m_curWW = -2048;
				ASSERT_VALID(pDoc);
				pDoc->dcm->setWindow(pDoc->m_curWC,pDoc->m_curWW);
				if(pDoc->pDicomDibits!=NULL)
					delete[]pDoc->pDicomDibits;
				int m_iDibSize=pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
				if(m_iDibSize==0)
					AfxMessageBox("createWindowsDIB����DIB�ļ�����");
				Invalidate();
			}
		}

		if (point.x>m_destX && point.y >m_destY && 
			point.x < (m_destX+m_destWidth) && point.y < (m_destY+m_destHeight))
		{
			m_pixelX = (point.x - m_destX)*pDoc->m_lpBMIH->biWidth/m_destWidth;
			m_pixelY = (point.y - m_destY)*pDoc->m_lpBMIH->biHeight/m_destHeight;

			//Uint8 *pixelData = (Uint8 *)(pDoc->dcm->getOutputData(8 /* bits per sample */));
			void *pixelData = (void *)pDoc->dcm->getInterData()->getData();
			if (pixelData != NULL)
			{
				EP_Representation pixelRep = pDoc->dcm->getInterData()->getRepresentation();
   
				switch(pixelRep)
				{
					case EPR_Uint8:
						// UCHAR;
						m_pixelValue = ((Uint8*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Sint8:
						//CHAR
						m_pixelValue = ((Sint8*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Uint16:
						//USHORT
						m_pixelValue = ((Uint16*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Sint16:
						// SHORT
						m_pixelValue = ((Sint16*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Uint32:
						//UINT
						m_pixelValue = ((Uint32*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
					case EPR_Sint32:
						//INT
						m_pixelValue = ((Sint32*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
						break;
				   default:
						m_pixelValue = ((Uint8*)pixelData)[m_pixelY*pDoc->m_lpBMIH->biWidth+m_pixelX];
			   }
			}

		}
		else
		{
			m_pixelX = 0;
			m_pixelY = 0;
		}
		
		InvalidateRect(CRect(0,view_height-2*txt_height,240,view_height-txt_height));//ˢ��value��ʾ���������
	}

}