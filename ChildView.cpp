
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Domin.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	CString strPl;
	strPl.Format(_T("Steve's Board"));
	
	bc1.draw(&dc);
	dc.SetBkColor(RGB(0, 255, 0));
	dc.SetTextColor(RGB(0, 0, 234));
	dc.TextOutW(50, 20, strPl);

	CString strSt;
	strSt.Format(_T("Your Board"));
	dc.SetTextColor(RGB(121, 121, 121));
	dc.TextOutW(450, 20, strSt);
	// Do not call CWnd::OnPaint() for painting messages
}



void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	bc1.mouseclick(point, &dc);
	CWnd::OnLButtonUp(nFlags, point);
}
