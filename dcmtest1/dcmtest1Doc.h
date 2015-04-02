
// dcmtest1Doc.h : Cdcmtest1Doc ��Ľӿ�
//

#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include <afx.h>
#pragma once


class Cdcmtest1Doc : public CDocument
{
protected: // �������л�����
	Cdcmtest1Doc();
	DECLARE_DYNCREATE(Cdcmtest1Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cdcmtest1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();
	DicomImage *dcm;
	LPBITMAPINFOHEADER m_lpBMIH;
	//void *pDicomDibits ;
	DcmFileFormat *pDicomFile;
	DcmDataset *pDataset;
	CString m_Pathname;
	CString strPicPath;
};
