
// seed2.0.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "Resource.h"		// 主符号


// Cseed20App:
// 有关此类的实现，请参阅 seed2.0.cpp
//

class Cseed20App : public CWinApp
{
public:
	Cseed20App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Cseed20App theApp;
