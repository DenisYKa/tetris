// Tetris.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
    #error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTetrisApp:
// �йش����ʵ�֣������ Tetris.cpp
//

class CTetrisApp : public CWinApp
{
public:
    CTetrisApp();
    ~CTetrisApp();

// ��д
public:
    virtual BOOL InitInstance();

// ʵ��
    MCIDEVICEID m_se_apprID;
    MCIDEVICEID m_se_turnID;
    MCIDEVICEID m_se_dsprID;
    MCIDEVICEID m_se_dsblID;
    MCIDEVICEID m_se_crsrID;
    MCIDEVICEID m_se_slctID;
    MCIDEVICEID m_me_gmvrID;
};

extern CTetrisApp theApp;