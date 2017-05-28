#include "Player.h"



void Player::changeentio()
{

	if (it == entios.end()){

		it = entios.begin();
	}
	else {
		it++;
	}

	movements--;
}

void Player::ataque()
{
	enti::InputKey num;
	enti::cout << enti::Color::MAGENTA << "1 - Sword" << enti::endl;
	enti::cout << enti::Color::MAGENTA << "2 - Bow" << enti::endl;
	num = enti::getInputKey();

	if (num == enti::InputKey::NUM1){

		enti::cout << enti::Color::BROWN << "Select direction to attack: W, A, S, D" << enti::endl;
		num = enti::getInputKey();

		switch (num)
		{
		case enti::InputKey::w:




			break;
		case enti::InputKey::W:
			break;
		case enti::InputKey::a:
			break;
		case enti::InputKey::A:
			break;
		case enti::InputKey::s:
			break;
		case enti::InputKey::S:
			break;
		case enti::InputKey::d:
			break;
		case enti::InputKey::D:
			break;
		default:
			break;
		}
		

	}

	else if (num == enti::InputKey::NUM2){


	}

	else{
		ataque();
	}
}

void Player::controlZX()
{

	if (moveback == true){

		int aux1;
		int aux2;

		mymapa.modificar(it->row, it->colum, it->last_char);
		it->last_char = mymapa.map[it->last_row][it->last_col];
		mymapa.modificar(it->last_row, it->last_col, it->letra);
		aux1 = it->row;
		aux2 = it->colum;
		it->row = it->last_row;
		it->colum = it->last_col;
		it->last_row = aux1;
		it->last_col = aux2;
		movements++;
		moveback = false;
		moveforward = true;

	} else if (moveforward == true){

		int aux1;
		int aux2;

		mymapa.modificar(it->row, it->colum, it->last_char);
		it->last_char = mymapa.map[it->last_row][it->last_col];
		mymapa.modificar(it->last_row, it->last_col, it->letra);
		aux1 = it->row;
		aux2 = it->colum;
		it->row = it->last_row;
		it->colum = it->last_col;
		it->last_row = aux1;
		it->last_col = aux2;
		movements--;
		moveback = true;
		moveforward = false;

	}
	
}

void Player::Move(enti::InputKey a)
{
	if (a == enti::InputKey::w || a == enti::InputKey::W)
	{
		if (mymapa.map[it->row - 1][it->colum] != 'X' && mymapa.map[it->row - 1][it->colum] != 'O')
		{
			mymapa.modificar(it->row, it->colum, it->last_char);
			it->last_col = it->colum;
			it->last_row = it->row;
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


void Player::reorder(){

	std::list<entio>::iterator it2 = entios.begin();
	entio aux;
	bool maspeque = false;


	for (int i = 0; i < entios.size() - 1; i++){

		std::list<entio>::iterator it3 = it2;
		it3++;

		for (int j = i + 1; j < entios.size(); j++){

			if (it3->fatiga < it2->fatiga){

				maspeque = true;
			}

			if (maspeque){
				aux = *it2;
				*it2 = *it3;
				*it3 = aux;
			}
			it3++;
		}
		it2++;
	}
}


Player::~Player()
{
}

