#include "Player.h"



Player::Player(bool letras, Mapa &a): mymapa(a)
{
	
	for (int i = 0; i < mymapa.max_rows; i++)
	{
		for (int j = 0; j < mymapa.max_cols; j++)
		{
			if (letras == true)
			{
				if (mymapa.map[i][j] >= 'A'&&mymapa.map[i][j] <= 'F')
				{
					entio a;
					a.colum = j;
					a.row = i;
					a.letra = mymapa.map[i][j];
					entios.push_back(a);
				}
			}
			else
			{
				if (mymapa.map[i][j] >= '1'&&mymapa.map[i][j] <= '6')
				{
					entio a;
					a.colum = j;
					a.row = i;
					a.letra = mymapa.map[i][j];
					entios.push_back(a);
				}
			}
		}
	}
	it= entios.begin();
}

Player::~Player()
{
}
