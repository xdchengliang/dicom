// RichStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "dcmtest1.h"
#include "RichStatic.h"


// CRichStatic

IMPLEMENT_DYNAMIC(CRichStatic, CStatic)

CRichStatic::CRichStatic():  
    m_clrText(RGB(255,255,255)), m_clrBackground(RGB(0,0,0))
{

}

CRichStatic::~CRichStatic()
{
}


BEGIN_MESSAGE_MAP(CRichStatic, CStatic)   
   ON_MESSAGE(WM_SETTEXT,OnSetText)  
   ON_WM_ERASEBKGND()  
END_MESSAGE_MAP()

// CRichStatic ��Ϣ�������  
  
  
void CRichStatic::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)  
{  
    if (m_clrBackground != CLR_NONE)    // ������ɫ��ΪCLR_NONE��CLR_NONE��ʾ�ޱ���ɫ��������Ʊ���  
    {  
        RECT rect;  
        GetWindowRect(&rect);  
        CBrush brush;  
        brush.CreateSolidBrush(m_clrBackground);  
        ::SelectObject(lpDrawItemStruct->hDC, brush.m_hObject);    // ���û�ˢ��ɫ  
        //::SelectObject(lpDrawItemStruct->hDC, GetStockObject(NULL_PEN));    // ���ñ�Ϊ�ձʣ������Ʊ߽磩  
        Rectangle(lpDrawItemStruct->hDC, 0, 0,rect.right - rect.left, rect.bottom - rect.top);  
    }  
  
  
    CString strCaption;    // ��������  
    GetWindowText(strCaption);  
    //if (m_hFont != NULL)  
    //{  
    //    ::SelectObject(lpDrawItemStruct->hDC, m_hFont);  
    //}  
  
  
    //// ��������ִ��ĺ�������   
    //int x = 0, y = 0;
    //if (X_LEFT != m_xAlignment || Y_TOP != m_yAlignment)    // �����������Ƕ�����  
    //{  
    //    CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);  
    //    CRect crect;  
    //    GetWindowRect(&crect);  
    //    CSize size = pDC->GetTextExtent(strCaption);  
    //    if (X_RIGHT == m_xAlignment)    // �Ҷ���  
    //    {  
    //        x = crect.Width() - size.cx;  
    //    }  
    //    else if (X_CENTER == m_xAlignment)   // X���ж���  
    //    {  
    //        x = (crect.Width()- size.cx) / 2;  
    //    }  
  
  
    //    if (Y_BOTTOM == m_yAlignment)   // ������  
    //    {  
    //        y = crect.Height() - size.cy;  
    //    }  
    //    else if (Y_CENTER == m_yAlignment)   // Y���ж���  
    //    {  
    //        y = (crect.Height() - size.cy) / 2;  
    //    }  
    //}  
    // ����dc�ִ���ɫ  
    ::SetTextColor(lpDrawItemStruct->hDC, m_clrText);  
    TextOut(lpDrawItemStruct->hDC, 0, 0, strCaption, strCaption.GetLength());  
}  
  
  
void CRichStatic::PreSubclassWindow()  
{  
    CStatic::PreSubclassWindow();  
    ModifyStyle(0, SS_OWNERDRAW);  
}  
  
  
//void CRichStatic::SetFont(CString strFaceName, LONG nHeight)  
//{  
//    if (m_selfCreated && m_hFont != NULL)  
//    {  
//        DeleteObject(m_hFont);    // ���������Ϊ�����Լ��������Ҳ�ΪNULL�������ٵ����ͷ��ں˶���  
//    }  
//    CFont cfont;  
//    LOGFONT lf;  
//    memset(&lf, 0, sizeof lf);    // ���LOGFONT�ṹ�壬֮����丳ֵ  
//    lf.lfHeight = nHeight;  
//    _tcscpy_s(lf.lfFaceName, strFaceName.GetBuffer());    // ��������������LOGFONT�ṹ����  
//    VERIFY(cfont.CreateFontIndirect(&lf));    // �����µ�����  
//    m_hFont = (HFONT)cfont.m_hObject;  
//    m_selfCreated = TRUE;    // �������Ϊ�Լ�������  
//}
  
  
BOOL CRichStatic::OnEraseBkgnd(CDC* pDC)  
{  
    // ������ɫΪ͸��ʱ����Ҫ�����뿽����ʾ�������ʾ����  
    if (m_clrBackground == CLR_NONE)  
    {  
        if (m_Bmp.GetSafeHandle() == NULL)  
        {  
            CRect Rect;  
            GetWindowRect(&Rect);  
            CWnd *pParent = GetParent();  
            ASSERT(pParent);  
            pParent->ScreenToClient(&Rect);  // ������ת��Ϊ�����Ի������Ӧ  
        
            // ������Ӧ����������ʾ������  
            CDC *pDC = pParent->GetDC();  
            CDC MemDC;  
            MemDC.CreateCompatibleDC(pDC);  
            m_Bmp.CreateCompatibleBitmap(pDC,Rect.Width(),Rect.Height());  
            CBitmap *pOldBmp = MemDC.SelectObject(&m_Bmp);  
            MemDC.BitBlt(0,0,Rect.Width(),Rect.Height(),pDC,Rect.left,Rect.top,SRCCOPY);  
            MemDC.SelectObject(pOldBmp);  
            MemDC.DeleteDC();    // ɾ���ڴ�DC�������ڴ�й©  
            pParent->ReleaseDC(pDC);  
        }  
        else // ��������ʾ�����ݿ�����ȥ  
        {  
            CRect Rect;  
            GetClientRect(Rect);  
            CDC MemDC;  
            MemDC.CreateCompatibleDC(pDC);  
            CBitmap *pOldBmp = MemDC.SelectObject(&m_Bmp);  
            pDC->BitBlt(0,0,Rect.Width(),Rect.Height(),&MemDC,0,0,SRCCOPY);  
            MemDC.SelectObject(pOldBmp);  
            MemDC.DeleteDC();    // ɾ���ڴ�DC�������ڴ�й©  
        }  
    }  
  
  
    return TRUE;  
}  
  
  
LRESULT CRichStatic::OnSetText(WPARAM wParam,LPARAM lParam)  
{  
    LRESULT Result = Default();  
    Invalidate();  
    UpdateWindow();  
    return Result;  
}

// CRichStatic ��Ϣ�������


