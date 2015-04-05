
// dcmtest1View.h : Cdcmtest1View ��Ľӿ�
//

#pragma once

#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/dcfilefo.h"
//#include "RichStatic.h"
#include <afxwin.h>

#define DCM_PatientName     DcmTagKey(0x0010, 0x0010)
#define DCM_PatientID		DcmTagKey(0x0010, 0x0020)
#define DCM_PatientBirth    DcmTagKey(0x0010, 0x0030)
#define DCM_PatientSex		DcmTagKey(0x0010, 0x0040)
#define DCM_Institution		DcmTagKey(0x0008, 0x0080)
#define DCM_PPSID			DcmTagKey(0x0020, 0x0010)
#define DCM_StudyDes		DcmTagKey(0x0008, 0x1030)
#define DCM_SeriesDes		DcmTagKey(0x0008, 0x103e)
#define DCM_WC				DcmTagKey(0x0028, 0x1050)
#define DCM_WW				DcmTagKey(0x0028, 0x1051)
#define DCM_CtnDate			DcmTagKey(0x0008, 0x0023)
#define DCM_CtnTime			DcmTagKey(0x0008, 0x0033)

class Cdcmtest1View : public CView
{
public: // �������л�����
	//DicomImage *pDicomImg;
	//DcmFileFormat *pDicomFile;
	//OFCondition Fcond;
	//Cdcmtest1View(DicomImage *p , DcmFileFormat *q);//OFCondition F);
	Cdcmtest1View();
	DECLARE_DYNCREATE(Cdcmtest1View)

// ����
public:
	Cdcmtest1Doc* GetDocument() const;
	
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~Cdcmtest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnShowTag();
	afx_msg void OnUpdateTagMenu(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDefaultWCWW();
	afx_msg void OnUpdateFullWCWW();
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

private:
	void UpdateLabelText(CDC* pDC);
public:
	DicomImage *dcm;
	DcmFileFormat *pDicomFile;
	DcmDataset *pDataset;

private:
	bool m_bShowTagEnable;

	double m_curWC;
	double m_curWW;
	bool isResetWindow;
	CPoint m_startPoint;
	CPoint m_curPoint;
	CPoint m_endPoint;
public:
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // dcmtest1View.cpp �еĵ��԰汾
inline Cdcmtest1Doc* Cdcmtest1View::GetDocument() const
   { return reinterpret_cast<Cdcmtest1Doc*>(m_pDocument); }
#endif

