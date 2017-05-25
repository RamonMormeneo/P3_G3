#include "Player.h"



void Player::Move(enti::InputKey a)
{
	if (a== enti::InputKey::w ||a == enti::InputKey::W)
	{
		if (mymapa.map[it->row - 1][it->colum]!='X' && mymapa.map[it->row - 1][it->colum] != 'O')
		{
			mymapa.modificar(it->row, it->colum,it->last_char);
			it->row--;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
		}
	}
	else if (a==enti::InputKey::a || a==enti::InputKey::A)
	{
		if (mymapa.map[it->row][it->colum-1] != 'X' && mymapa.map[it->row][it->colum-1] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->colum--;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
		}
	}
	else if (a == enti::InputKey::s || a == enti::InputKey::S)
	{
		if (mymapa.map[it->row+1][it->colum] != 'X' && mymapa.map[it->row+1][it->colum] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->row++;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
		}
	}
	else if (a == enti::InputKey::d || a == enti::InputKey::D)
	{
		if (mymapa.map[it->row][it->colum + 1] != 'X' && mymapa.map[it->row][it->colum + 1] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->colum++;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
		}
	}
}

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
