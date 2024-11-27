#pragma once
#include "CHcn.h"
class Omin :
    public CHcn
{
public:
    int thuyen ;
    int sl;
    int dong ;
    Omin() :CHcn() 
    {
        thuyen = 0;
        dong = 1;
        //dong = 0;//de test
    }
    void draw(CClientDC* pdc);
    void draw(CPaintDC* pdc);
};

