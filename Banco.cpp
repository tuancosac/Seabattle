#include "pch.h"
#include "Banco.h"
#include "random"
Banco::Banco()
{
	std::random_device rd; // Sinh số ngẫu nhiên thực sự (nếu có)
	std::mt19937 gen(rd()); // Mersenne Twister engine

	
	std::uniform_int_distribution<> dist(0, 9);
	control = 1;
	// Sinh số ngẫu nhiên
	int randomNumber = dist(gen);
	int xm = 50, ym = 50;
	int d = 30;
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			Mang1[i][j].setHcn(xm + j * d, ym + i * d, xm + j * d + d, ym + i * d + d);

		}
	}
	int xm1 = 400, ym1 = 50;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Mang2[i][j].setHcn(xm1 + j * d, ym1 + i * d, xm1 + j * d + d, ym1 + i * d + d);
		}
	}
	int dem1 = 0;
	int rani1 = 0, ranj1 = 0;
	while (dem1 < 10)
	{
		rani1 = dist(gen);
		ranj1 = dist(gen);
		if (Mang1[rani1][ranj1].thuyen == 0)
		{
			Mang1[rani1][ranj1].thuyen = 1;
			dem1++;
		}

	}
	int dem2 = 0;
	int rani2 = 0, ranj2 = 0;
	while (dem2 < 10)
	{
		rani2 = dist(gen);
		ranj2 = dist(gen);
		if (Mang2[rani2][ranj2].thuyen == 0)
		{
			Mang2[rani2][ranj2].thuyen = 1;
			Mang2[rani2][ranj2].dong = 0;
			dem2++;
		}

	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Mang1[i][j].thuyen != 1)
			{
				//Mang1[i][j].sl = xungquanhthuyen(i, j);
				Mang1[i][j].sl = 1;
			}
		}
	}
}

void Banco::draw(CPaintDC* dc)
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			Mang1[i][j].draw(dc);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Mang2[i][j].draw(dc);
		}
	}
}

void Banco::draw(CClientDC* pdc)
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < 10; j++)
		{
			Mang1[i][j].draw(pdc);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Mang2[i][j].draw(pdc);
		}
	}
}

void Banco::xungquanhthuyen(int mi, int mj)//cai lay ch cho vao dc
{
	if (Mang1[mi][mj].thuyen == 0)
	{
		Mang1[mi][mj].dong = 0;
	}
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (mi + i >= 0 && mi + i < 10 && mj + j >= 0 && mj + j < 10)
			{
				if (i != 0 || j != 0)
				{
					xungquanhthuyen(mi + i, mj + j);
				}
			}
		}
	}
}


void Banco::mouseclick(CPoint p, CClientDC* pdc)
{
	
	int extrapress = 0;
	if (control == 1)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, 9);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{

				if (Mang1[i][j].Kttronghinh(p) == 1 && Mang1[i][j].bcolor == 1)
				{
					
					Mang1[i][j].bcolor = 4;
					Mang1[i][j].dong = 0;
					Mang1[i][j].draw(pdc);
					if (Mang1[i][j].thuyen == 1)
					{
						Mang1[i][j].bcolor = 2;
						Mang1[i][j].draw(pdc);
						extrapress++;
						//nguoiwin++;
						if (ktraWin(i, j) == 0)
						{
							control = 0;
							return; // End the game if a winner is found
						}
						
						
						//return;
					}
					
					int randomcount = 1;
					while (randomcount > 0)
					{
						int rani2 = dist(gen);
						int ranj2 = dist(gen);
						if (Mang2[rani2][ranj2].bcolor == 1)
						{
							
							if (Mang2[rani2][ranj2].thuyen == 1)
							{
								Mang2[rani2][ranj2].bcolor = 2;
								Mang2[rani2][ranj2].draw(pdc);
								randomcount++;
								//botwin++;
								
							}
							else
							{
								Mang2[rani2][ranj2].bcolor = 3;
								Mang2[rani2][ranj2].draw(pdc);
							}
							
							randomcount--;
							if (ktraWin(rani2, ranj2) == 0)
							{
								control = 0;
								return; // End the game if a winner is found
							}
						}
						
					}
					return;
				}
			}
			
		}
		
		
	}
	

}

void Banco::xuatWin(CClientDC* dc)
{
	CString strx, stro;
	strx.Format(_T("You win"));
	stro.Format(_T("Steve win"));
	int xmoi = 20;
	int ymoi = 20;
}

int Banco::ktraWin(int mi, int mj)
{

	bool allShipsSunkMang1 = true;
	bool allShipsSunkMang2 = true;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Mang1[i][j].thuyen == 1 && Mang1[i][j].bcolor != 2)
			{
				allShipsSunkMang1 = false;
			}
			if (Mang2[i][j].thuyen == 1 && Mang2[i][j].bcolor != 2)
			{
				allShipsSunkMang2 = false;
			}
		}
	}

	if (allShipsSunkMang1)
	{
		MessageBoxW(NULL, _T("You wins!"), _T("Sugoiiiii"), MB_OK | MB_ICONINFORMATION);
		return 0; // Game over: Bot wins
	}
	if (allShipsSunkMang2)
	{
		MessageBoxW(NULL, _T("Steve win!"), _T("Game Over"), MB_OK | MB_ICONINFORMATION);
		return 0; // Game over: Player wins
	}

	return 1; // Game continues
}
	



	


