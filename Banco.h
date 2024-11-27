#pragma once
#include "Omin.h"
class Banco
{
public:
	Omin Mang1[10][10];
	Omin Mang2[10][10];
	Banco();
	int control;
	void draw(CPaintDC* pdc);
	void draw(CClientDC* pdc);
	void xungquanhthuyen(int mi, int mj);
	void mouseclick(CPoint p, CClientDC* dc);
	void xuatWin(CClientDC* dc);
	//bool checkWin(bool isPlayer);
	int ktraWin(int mi, int mj);
	//int ktraWin();
};

