#include "pch.h"
#include "Omin.h"

void Omin::draw(CClientDC* pdc)
{
	CHcn::draw(pdc);
	if (dong == 0) 
	{
		int xmoi = (x1 + x2) / 2-5;
		int ymoi = (y1 + y2) / 2-8;
		CString str;
		str.Format(_T("%d"), sl);
		pdc->MoveTo(xmoi, ymoi);
		if (thuyen == 1) 
		{
			pdc->SetBkMode(TRANSPARENT);
			pdc->TextOutW(xmoi, ymoi, CString("X"));
			pdc->SetTextColor(RGB(121, 121, 121));
		}
		else
		{
			if (sl>0)
				pdc->SetBkMode(TRANSPARENT);
				pdc->TextOutW(xmoi, ymoi, CString("0"));
				pdc->SetTextColor(RGB(121, 121, 121));
		}
		
	}
}

void Omin::draw(CPaintDC* pdc)
{
	CHcn::draw(pdc);
	if (dong == 0)
	{
		int xmoi = (x1 + x2) / 2-5;
		int ymoi = (y1 + y2) / 2-8;
		CString str;
		str.Format(_T("%d"), sl);
		pdc->MoveTo(xmoi, ymoi);
		if (thuyen == 1)
		{
			pdc->SetBkMode(TRANSPARENT);
			pdc->TextOutW(xmoi, ymoi, CString("X"));
			pdc->SetTextColor(RGB(255, 214, 0));
			//pdc->SetBkColor(RGB(0, 0, 255));
			//pdc->SetBkMode(OPAQUE);
		}
		else
		{
			if (sl > 0)
				pdc->SetBkMode(TRANSPARENT);
				pdc->TextOutW(xmoi, ymoi, CString("0"));
				pdc->SetTextColor(RGB(255,0,0));
				//pdc->SetBkColor(RGB(0, 0, 255));
				//pdc->SetBkMode(OPAQUE);
		}
	}
}
