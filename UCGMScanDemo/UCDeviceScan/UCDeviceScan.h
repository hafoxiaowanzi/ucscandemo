
// MFCApplication1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCApplication1App: 
// �йش����ʵ�֣������ MFCApplication1.cpp
//

class CUCDeviceScanApp : public CWinApp
{
public:
	CUCDeviceScanApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CUCDeviceScanApp theApp;