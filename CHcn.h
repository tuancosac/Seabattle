#pragma once
class CHcn
{
public:
	int x1, y1, x2, y2;
	int bcolor;
	CHcn();
	CHcn(int x1, int y1, int x2, int y2);
	void setHcn(int x1, int y1, int x2, int y2);
	void draw(CPaintDC* dc);
	void draw(CClientDC* dc);
	int Kttronghinh(CPoint p);
};

