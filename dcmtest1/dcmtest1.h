
// dcmtest1.h : dcmtest1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

// Cdcmtest1App:
// �йش����ʵ�֣������ dcmtest1.cpp
//

class Cdcmtest1App : public CWinApp
{
public:
	Cdcmtest1App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cdcmtest1App theApp;
