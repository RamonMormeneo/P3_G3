#include "Player.h"



void Player::changeentio()
{
}

void Player::ataque()
{
}

void Player::controlZX()
{
}

void Player::Move(enti::InputKey a)
{
	if (a == enti::InputKey::w || a == enti::InputKey::W)
	{
		if (mymapa.map[it->row - 1][it->colum] != 'X' && mymapa.map[it->row - 1][it->colum] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->row--;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
			moveback = true;
		}
	}
	else if (a == enti::InputKey::a || a == enti::InputKey::A)
	{
		if (mymapa.map[it->row][it->colum - 1] != 'X' && mymapa.map[it->row][it->colum - 1] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->last_col = it->colum;
			it->last_row = it->row;
			it->colum--;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
			moveback = true;
		}
	}
	else if (a == enti::InputKey::s || a == enti::InputKey::S)
	{
		if (mymapa.map[it->row + 1][it->colum] != 'X' && mymapa.map[it->row + 1][it->colum] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->last_col = it->colum;
			it->last_row = it->row;
			it->row++;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
			moveback = true;
		}
	}
	else if (a == enti::InputKey::d || a == enti::InputKey::D)
	{
		if (mymapa.map[it->row][it->colum + 1] != 'X' && mymapa.map[it->row][it->colum + 1] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->last_col = it->colum;
			it->last_row = it->row;
			it->colum++;
			it->last_char = mymapa.map[it->row][it->colum];
			mymapa.modificar(it->row, it->colum, it->letra);
			it->fatiga++;
			movements--;
			moveback = true;
		}
	}
}

void Player::Input(enti::InputKey a)
{
	switch (a)
	{
	case enti::InputKey::NONE:
		break;
	case enti::InputKey::ENTER:
		changeentio();
		break;
	case enti::InputKey::SPACEBAR:
		ataque();
		break;
	case enti::InputKey::ESC:
		exit(0);
		break;
	default:
		if (a == enti::InputKey::w || a == enti::InputKey::W)
		{
			Move(a);
		}
		else if (a == enti::InputKey::a || a == enti::InputKey::A)
		{
			Move(a);
		}
		else if (a == enti::InputKey::s || a == enti::InputKey::S)
		{
			Move(a);
		}
		else if (a == enti::InputKey::d || a == enti::InputKey::D)
		{
			Move(a);
		}
		else if((a == enti::InputKey::z || a == enti::InputKey::Z))
		{
			controlZX();
		}
		else if ((a == enti::InputKey::x || a == enti::InputKey::X))
		{
			controlZX();
		}
		break;
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
