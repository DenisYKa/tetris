// Blcok.cpp : ʵ���ļ�
//

#include "StdAfx.h"
#include "Block.h"
#include "Tetris.h"

Block::Block(unsigned char clr, unsigned char **board)
{
    row = 0;                                                            // ��һ��
    col = 4;                                                            // ������
    dir = 0;                                                            // ��һ�ַ���
    this->clr = clr;
    this->board = board;
}