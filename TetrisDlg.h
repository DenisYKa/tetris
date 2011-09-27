// TetrisDlg.h : ͷ�ļ�
//

#pragma once
#include "block.h"

// CTetrisDlg �Ի���
class CTetrisDlg : public CDialog
{
// ����
public:
	CTetrisDlg(CWnd* pParent = NULL);	                // ��׼���캯��
    ~CTetrisDlg();

// �Ի�������
	enum
    {
        IDD = IDD_TETRIS_DIALOG,
        ROW = 20,
        COL = 10,
        WIDTH = COL << 5,
        HEIGHT = ROW << 5
    };

protected:
    BOOL PreTranslateMessage(MSG *pMsg);

// ʵ��
protected:
	HICON m_hIcon;


private:
    CMenu m_menu;                                           // ���˵�
    CImage m_bk;                                            // ����ͼƬ����
    CImage m_block;                                         // ����ͼƬ����
    CImage m_window;                                        // ����ͼƬ����
    CImage m_gameover;                                      // ��Ϸ����ͼƬ����
    CDC m_memDC;                                            // ��������豸������
    CBitmap m_memBmp;                                       // �������λͼ
    CClientDC *m_pDC;                                       // �ͻ����豸������

    BYTE **m_board;                                         // ���̣�������
    Block *m_pBlock;                                        // ��ǰ�����ָ��
    BYTE m_level;                                           // ��Ϸ�Ѷ�
    BYTE m_gameParam;                                       // ��Ϸ������λ->0: ��Ϸ��ʼ, 1: ��Ϸ��ͣ, 2: ��Ϸʧ��, 3: ��Ч, 4: �������, 5-7: ��һ�����飩
    BYTE m_nextColor;                                       // ��һ���������ɫ
    UINT m_lines;                                           // ��������
    UINT m_score;                                           // ����
    BYTE m_mouseOver;                                       // ��꽹�㣨λ->0: NEW, 1: PAUSE, 2: STOP, 3: SOUND, 4:EXIT��

    void Update();                                          // ȫ��ˢ��
    void AdjustFrame();                                     // ���ݿͻ�����С���ڴ��ڳߴ�
    void Initialize();                                      // ��ʼ����Ϸ
    void RedrawBkgnd(RECT rect);                            // �ػ汳��ͼƬ
    void DrawText(SHORT x1, SHORT y1, SHORT x2, SHORT y2,
        CString &text, UINT format, COLORREF clr);          // �������
    void SetFontSize(BYTE size);                            // ���������С
    void Play(MCIDEVICEID id);                              // ������Ч
    void UpdateBlock();                                     // ���·���ͼ��
    void UpdateWindow();                                    // ���´���
    void NextRandomBlock();                                 // ������һ��������������
    BYTE NextRandomColor();                                 // ������һ������������ɫ
    Block *BlockFromIndex(BYTE i);                          // �ӷ���������ȡ�������
    BOOL CheckLine(BYTE row);                               // ���һ���Ƿ������
    void RemoveLine(BYTE row);                              // ����һ��
    BOOL IsGameOver(BYTE blockType);                        // �Ƿ���Ϸʧ��
    void GameOver();                                        // ��Ϸʧ��

public:
    // ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg UINT OnGetDlgCode();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnGameNew();
    afx_msg void OnGamePause();
    afx_msg void OnGameStop();
    afx_msg void OnLevelBeginner();
    afx_msg void OnLevelIntermediate();
    afx_msg void OnLevelAdvanced();
    afx_msg void OnLevelExpert();
    afx_msg void OnLevelDevil();
    afx_msg void OnLevelHell();
    afx_msg void OnGameSound();
    afx_msg void OnGameExit();
	afx_msg void OnHelpAbout();
	DECLARE_MESSAGE_MAP()
};

// CAboutDlg dialog
class CAboutDlg : public CDialog
{
public:
    CAboutDlg(CWnd* pParent = NULL) : CDialog(CAboutDlg::IDD, pParent) {}

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

};