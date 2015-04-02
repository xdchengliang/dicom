#pragma once


// CRichStatic

class CRichStatic : public CStatic
{
	DECLARE_DYNAMIC(CRichStatic)

public:
	CRichStatic();
	virtual ~CRichStatic();

protected:    
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);  
    afx_msg LRESULT OnSetText(WPARAM,LPARAM);
	DECLARE_MESSAGE_MAP()

	virtual void PreSubclassWindow();  
  
private:  
    COLORREF m_clrText;          // ����ǰ��ɫ  
    COLORREF m_clrBackground;    // ���ֱ���ɫ  
    //CFont *m_pTextFont;          // ��������  
    CBitmap m_Bmp;               // ���汳���õ�λͼ����  
public:  
    // ���ñ���ɫ����clrΪCLR_NONE���򱳾�͸����  
    void SetBackgroundColor(COLORREF clr){m_clrBackground = clr;}  
    // ��������ǰ��ɫ  
    void SetTextColor(COLORREF clr){m_clrText = clr;}  
    // ������������  
    //void SetFont(CString strFaceName, LONG nHeight);  
  
public:  
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/); 
};


