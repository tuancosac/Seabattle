#include "pch.h"
#include "CHcn.h"

CHcn::CHcn()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	bcolor = 1;
}

CHcn::CHcn(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	bcolor = 1;
}

void CHcn::setHcn(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void CHcn::draw(CPaintDC* dc)
{
	CBrush blueBrush(RGB(0, 0, 255));
	CBrush redBrush(RGB(255, 0, 0));
	CBrush greenBrush(RGB(0, 255, 0));
	CBrush whiteBrush(RGB(255, 255, 255));
	CBrush* pOldBrush = new CBrush();
	if (bcolor == 1)
	{
		pOldBrush = dc->SelectObject(&blueBrush);
	}
	else if (bcolor == 2)
	{
		pOldBrush = dc->SelectObject(&redBrush);
	}
	else if (bcolor == 3)
	{
		pOldBrush = dc->SelectObject(&greenBrush);
	}
	else if (bcolor == 4)
	{
		pOldBrush = dc->SelectObject(&whiteBrush);
	}
	dc->Rectangle(x1, y1, x2, y2);
	if (bcolor == 1 || bcolor == 2 || bcolor == 3 || bcolor == 4)
	{
		dc->SelectObject(pOldBrush);
	}
}

void CHcn::draw(CClientDC* dc)
{
	CBrush blueBrush(RGB(0, 0, 255));
	CBrush redBrush(RGB(255, 0, 0));
	CBrush greenBrush(RGB(0, 255, 0));
	CBrush whiteBrush(RGB(255, 255, 255));
	CBrush* pOldBrush = new CBrush();
	if (bcolor == 1)
	{
		pOldBrush = dc->SelectObject(&blueBrush);
	}
	else if (bcolor == 2)
	{
		pOldBrush = dc->SelectObject(&redBrush);
	}
	else if (bcolor == 3)
	{
		pOldBrush = dc->SelectObject(&greenBrush);
	}
	else if (bcolor == 4)
	{
		pOldBrush = dc->SelectObject(&whiteBrush);
	}
	dc->Rectangle(x1, y1, x2, y2);
	if (bcolor == 1 || bcolor == 2 || bcolor == 3||bcolor ==4)
	{
		dc->SelectObject(pOldBrush);
	}
}

int CHcn::Kttronghinh(CPoint p)
{
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		return 1;
	return 0;
}


