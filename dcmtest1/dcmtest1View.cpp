
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
	ON_COMMAND(ID_WCWW_Default , OnUpdateDefaultWCWW)
	ON_COMMAND(ID_WCWW_FULL , OnUpdateFullWCWW)
	ON_WM_CREATE()
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
	m_curWC(0),
	m_curWW(0),
	m_WCWWtype(0)
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



	//double min,max;
	//dcm->getMinMaxValues(min,max);
	//EI_Status status = dcm->getStatus();
	//FILE* f = fopen("D:\\Guo_Yu\\Project\\dcmdata\\AELQYFNH\\temp.bmp","wb");
	//dcm->writeBMP(f,8);
	//fclose(f);

	//LPBITMAPINFOHEADER m_lpBMIH;
	//m_lpBMIH = (LPBITMAPINFOHEADER) new char[sizeof(BITMAPINFOHEADER)
	//	+sizeof(RGBQUAD)*256];
	//m_lpBMIH->biSize = sizeof(BITMAPINFOHEADER);
	//m_lpBMIH->biWidth =dcm->getWidth();
	//m_lpBMIH->biHeight = dcm->getHeight();
	//m_lpBMIH->biPlanes = 1;
	//m_lpBMIH->biBitCount = 24;
	//m_lpBMIH->biCompression = BI_RGB;
	//m_lpBMIH->biSizeImage = 0;
	//m_lpBMIH->biXPelsPerMeter = 0;
	//m_lpBMIH->biYPelsPerMeter = 0;
	//double centre,width;
	//double min,max;
	//dcm->getMinMaxValues(min,max);
	////dcm->getWindow(centre,width);
	//width = max-min;
	//centre = (max+min)/2;
	//dcm->setWindow(35,320);

	//dcm->setHistogramWindow();

	//void *pDicomDibits ;
	//dcm->createWindowsDIB(pDicomDibits,0,0,24,1,1);

//	RGBQUAD pColorTable[256];
//	for(int i=0;i<256;i++)
//	{
//
//		pColorTable[i].rgbBlue=i;
//		pColorTable[i].rgbGreen=i;
//		pColorTable[i].rgbRed=i;
//		pColorTable[i].rgbReserved=0;
//	}
//	//����һ��bmpinfo��Ҫ�ڴ��С���ڴ�
//	char p[sizeof(BITMAPINFOHEADER)+256*4];
//	memcpy(p,&m_lpBMIH,sizeof(BITMAPINFOHEADER));
//	memcpy(p+sizeof(BITMAPINFOHEADER),pColorTable,1024);
//	PBITMAPINFO BitmapInfo = (PBITMAPINFO)p;
//
//
////��ɫ��
// int colorTableLng;
// colorTableLng=256;
//
// // ������ɫ��
// HPALETTE hPalette=0,hOldPal;
// if (colorTableLng!=0)
// {
//  //������ɫ��ָ��pColorTable,ָ��DIB����ɫ��
//  //���뻺����������LOGPALETTE�ṹ
//  LPLOGPALETTE pLogPal = (LPLOGPALETTE)new char[2*sizeof(WORD)
//   +colorTableLng * sizeof(PALETTEENTRY)];
//  pLogPal->palVersion = 0x300;
//  pLogPal->palNumEntries =colorTableLng;
//  for(int i = 0; i < colorTableLng; i++)
//  {
//   pLogPal->palPalEntry[i].peRed= pColorTable[i].rgbRed;
//   pLogPal->palPalEntry[i].peGreen =pColorTable[i].rgbGreen;
//   pLogPal->palPalEntry[i].peBlue = pColorTable[i].rgbBlue;
//   pLogPal->palPalEntry[i].peFlags = 0;
//  }
//
//  //
//  //�����߼���ɫ��
//  hPalette =::CreatePalette(pLogPal);
//  // ����ɫ��ѡ��ϵͳ
//  hOldPal=::SelectPalette(pDC->GetSafeHdc(), hPalette, TRUE);
//  //ʵ�ֵ�ɫ��
//  pDC->RealizePalette();
//  //�ͷŻ�����
//  delete []pLogPal;
// }
//
// //
// //DIB��ʾ����Ҫ��ģʽ
// pDC->SetStretchBltMode(COLORONCOLOR);

	//Set the view background color
	CBrush   backBrush(RGB(0, 0,0));
              //   �����ˢ��  
    pDC->SelectObject(&backBrush);  
    CRect   rect;
    pDC->GetClipBox(&rect);           //   �������������  
    pDC->PatBlt(rect.left,rect.top,rect.Width(),rect.Height(),PATCOPY); 

	if(pDoc->dcm != NULL)
	{
		//CRect rect;
		//GetClientRect(&rect);
		int destX,destY,destWidth,destHeight;
		destHeight = rect.Height();
		destWidth = pDoc->m_lpBMIH->biWidth*destHeight/pDoc->m_lpBMIH->biHeight;
		destX = (rect.Width() - destWidth)/2;
		destY = 0;


		StretchDIBits(pDC->GetSafeHdc(),destX,destY,destWidth,
			destHeight,0,0,pDoc->m_lpBMIH->biWidth,
			pDoc->m_lpBMIH->biHeight,pDoc->pDicomDibits,
			(LPBITMAPINFO)pDoc->m_lpBMIH,DIB_PAL_COLORS,SRCCOPY);
		m_bShowTagEnable = true;
		
		UpdateLabelText();
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
		m_curWC = atof(wc.c_str());
		m_curWW = atof(ww.c_str());
		pDoc->dcm->setWindow(m_curWC,m_curWW);
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
	m_curWC = (max-min)/2;
	m_curWW = (max+min)/2;
	pDoc->dcm->setWindow(m_curWC,m_curWW);

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


int Cdcmtest1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CRect rect(0,0,0,0);

	m_textPatName.Create("test", WS_CHILD|WS_VISIBLE, rect, this, IDC_PatName);
	m_textPatName.ShowWindow(SW_SHOWNORMAL);

	m_textPatID.Create("testtest", WS_CHILD|WS_VISIBLE, rect, this, IDC_PatID);
	m_textPatID.ShowWindow(SW_SHOWNORMAL);

	m_textPatBirth.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_PatBirth);
	m_textPatBirth.ShowWindow(SW_SHOWNORMAL);

	m_textPatGender.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_PatGender);
	m_textPatGender.ShowWindow(SW_SHOWNORMAL);

	m_textInstitution.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_Institution);
	m_textInstitution.ShowWindow(SW_SHOWNORMAL);

	m_textPPSID.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_PPSID);
	m_textPPSID.ShowWindow(SW_SHOWNORMAL);

	m_textStudyDes.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_StudyDes);
	m_textStudyDes.ShowWindow(SW_SHOWNORMAL);

	m_textSeriesDes.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_SeriesDes);
	m_textSeriesDes.ShowWindow(SW_SHOWNORMAL);

	m_textPixelValue.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_PixelValue);
	m_textPixelValue.ShowWindow(SW_SHOWNORMAL);

	m_textWC.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_WC);
	m_textWC.ShowWindow(SW_SHOWNORMAL);

	m_textWW.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_WW);
	m_textWW.ShowWindow(SW_SHOWNORMAL);

	m_textCtnDate.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_CtnDate);
	m_textCtnDate.ShowWindow(SW_SHOWNORMAL);

	m_textCtnTime.Create("", WS_CHILD|WS_VISIBLE, rect, this, IDC_CtnTime);
	m_textCtnTime.ShowWindow(SW_SHOWNORMAL);

	return 0;
}

void Cdcmtest1View::UpdateLabelText()
{
	Cdcmtest1Doc* pDoc = GetDocument();

	int txt_width = 240;
	int txt_height = 20;
    CRect   rect;
    GetClientRect(&rect);
	int view_width = rect.Width();
	int view_height = rect.Height();
	m_textPatName.MoveWindow(CRect(view_width-txt_width, 0, view_width, txt_height));
	m_textPatID.MoveWindow(CRect(view_width-txt_width, txt_height, view_width, 2*txt_height));
	m_textPatBirth.MoveWindow(CRect(view_width-txt_width, 2*txt_height, view_width-txt_width/6, 3*txt_height));
	m_textPatGender.MoveWindow(CRect(view_width-txt_width/6, 2*txt_height, view_width, 3*txt_height));
	m_textInstitution.MoveWindow(CRect(view_width-txt_width, 3*txt_height, view_width, 4*txt_height));
	m_textPPSID.MoveWindow(CRect(view_width-txt_width, 4*txt_height, view_width, 5*txt_height));
	m_textStudyDes.MoveWindow(CRect(view_width-txt_width, 5*txt_height, view_width, 6*txt_height));
	m_textSeriesDes.MoveWindow(CRect(view_width-txt_width, 6*txt_height, view_width, 7*txt_height));

	
	m_textPixelValue.MoveWindow(CRect(0, view_height-2*txt_height, txt_width, view_height-txt_height));
	m_textWC.MoveWindow(CRect(0, view_height-txt_height, txt_width/2, view_height));
	m_textWW.MoveWindow(CRect(txt_width/2, view_height-txt_height, txt_width, view_height));

	m_textCtnDate.MoveWindow(CRect(view_width-txt_width, view_height-txt_height, view_width-txt_width/2, view_height));
	m_textCtnTime.MoveWindow(CRect(view_width-txt_width/2, view_height-txt_height, view_width, view_height));

	OFString tempstring;
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientName, tempstring).good())
	{
		m_textPatName.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientID, tempstring).good())
	{
		m_textPatID.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientBirth, tempstring).good())
	{
		m_textPatBirth.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PatientSex, tempstring).good())
	{
		m_textPatGender.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_Institution, tempstring).good())
	{
		m_textInstitution.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_PPSID, tempstring).good())
	{
		m_textPPSID.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_StudyDes, tempstring).good())
	{
		m_textStudyDes.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_SeriesDes, tempstring).good())
	{
		m_textSeriesDes.SetWindowTextA(tempstring.c_str());
	}

	char wc_ww[10];
	itoa(m_curWC, wc_ww, 10);
	m_textWC.SetWindowTextA(wc_ww);

	itoa(m_curWW, wc_ww, 10);
	m_textWW.SetWindowTextA(wc_ww);


	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_CtnDate, tempstring).good())
	{
		m_textCtnDate.SetWindowTextA(tempstring.c_str());
	}
	tempstring.clear();
	if (pDoc->pDataset->findAndGetOFString(DCM_CtnTime, tempstring).good())
	{
		m_textCtnTime.SetWindowTextA(tempstring.c_str());
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

	if (isResetWindow && pDoc->dcm!=NULL) 
	{
		if(abs(point.x-m_curPoint.x)+abs(point.y-m_curPoint.y)>10)
		{
			printf("m_curPoint.x = %d, m_curPoint.y = %d \r\n",m_curPoint.x, m_curPoint.y);
			printf("point.x = %d, point.y = %d \r\n",point.x, point.y);
			m_curWC=m_curWC+(-point.x+m_curPoint.x);
			m_curWW=m_curWW+(point.y-m_curPoint.y);
			m_curPoint.x=point.x;
			m_curPoint.y=point.y;
			if(m_curWC>2047)
				m_curWC=2047;
			if(m_curWC<-2048)
				m_curWC=-2048;
			if(m_curWW>2047)
				m_curWW=2047;
			if(m_curWW<-2048)
				m_curWW = -2048;
			ASSERT_VALID(pDoc);
			pDoc->dcm->setWindow(m_curWC,m_curWW);
			if(pDoc->pDicomDibits!=NULL)
				delete[]pDoc->pDicomDibits;
			int m_iDibSize=pDoc->dcm->createWindowsDIB(pDoc->pDicomDibits,0,0,24,1,1);
			if(m_iDibSize==0)
				AfxMessageBox("createWindowsDIB����DIB�ļ�����");
			Invalidate();
		}
	}
}

