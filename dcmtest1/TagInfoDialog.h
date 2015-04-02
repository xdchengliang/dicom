#pragma once

#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmdata/dcelem.h"
#include "afxcmn.h"


// TagInfoDialog �Ի���

class TagInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TagInfoDialog)

public:
	TagInfoDialog(DcmItem* pDSet, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TagInfoDialog();

// �Ի�������
	enum { IDD = IDD_TAGINFODIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_tagList;

private:
	DcmItem* m_dataSet;
};
