#include "Player.h"



void Player::changeentio()
{
	if (it != it2){
		it++;
		
	}
	else if (it == it2)
	{
		it = entios.begin();
	}
	movements--;
}

void Player::ataque(std::list <entio> a)
{
	enti::InputKey num;
	enti::cout << enti::Color::MAGENTA << "1 - Sword" << enti::endl;
	enti::cout << enti::Color::MAGENTA << "2 - Bow" << enti::endl;
	enti::cout << enti::cend;
	bool hit;
	num= enti::getInputKey();
	while (num == enti::InputKey::NONE)
	{
		num = enti::getInputKey();
	}
	
	if (num == enti::InputKey::NUM1) {

		enti::cout << enti::Color::BROWN << "Select direction to attack: W, A, S, D" << enti::endl;
		enti::cout << enti::cend;
		num = enti::getInputKey();
		while (num == enti::InputKey::NONE)
		{
			num = enti::getInputKey();
		}
		if (num == enti::InputKey::w || num == enti::InputKey::W)
		{
			int objectiverow = it->row - 1;
			int objectivecol = it->colum;
			for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
			{
				if (objectiverow == i->row && objectivecol == i->colum)
				{
					enti::cout << enti::Color::BROWN << "You have slain the entio " << i->letra << enti::endl;
				
					a.erase(i);
				}
			}
		}
		else if (num == enti::InputKey::s || num == enti::InputKey::S)
		{
			int objectiverow = it->row + 1;
			int objectivecol = it->colum;
			for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
			{
				if (objectiverow == i->row && objectivecol == i->colum)
				{
					enti::cout << enti::Color::BROWN << "You have slain the entio " << i->letra << enti::endl;
					enti::cout << enti::cend; 
					a.erase(i);
				}
			}
		}
		else if (num == enti::InputKey::a || num == enti::InputKey::A)
		{
			int objectiverow = it->row;
			int objectivecol = it->colum - 1;
			for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
			{
				if (objectiverow == i->row && objectivecol == i->colum)
				{
					enti::cout << enti::Color::BROWN << "You have slain the entio " << i->letra << enti::endl;
					enti::cout << enti::cend;
					a.erase(i);
				}
			}
		}
		else if (num == enti::InputKey::d || num == enti::InputKey::D)
		{
			int objectiverow = it->row;
			int objectivecol = it->colum + 1;
			for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
			{
				if (objectiverow == i->row && objectivecol == i->colum)
				{
					enti::cout << enti::Color::BROWN << "You have slain the entio " << i->letra << enti::endl;
					enti::cout << enti::cend;
					a.erase(i);
				}
			}
		}
		movements--;
	}

	else if (num == enti::InputKey::NUM2)
	{
		enti::cout << enti::Color::BROWN << "Select direction to attack: W, A, S, D" << enti::endl;
		enti::cout << enti::cend;
		num = enti::getInputKey();
		while (num == enti::InputKey::NONE)
		{
			num = enti::getInputKey();
		}
		bool hit = false;

		if (num == enti::InputKey::w || num == enti::InputKey::W)
		{
			int objectiverow = it->row - 3;
			int objectivecol = it->colum;
			if (objectiverow > 0)
			{
				int aux = 8;
				while (objectiverow > objectiverow - 7 && mymapa.map[objectiverow][objectivecol] != 'X')
				{
					for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
					{
						if (objectiverow == i->row && objectivecol == i->colum && !hit)
						{
							i->life -= aux;
							enti::cout << enti::Color::BROWN << "The damage done to the entio " << i->letra << " is " << aux << " current entio life " << i->life << enti::endl;
							enti::cout << enti::cend;
							if (i->life == 0)
							{
								enti::cout << enti::Color::BROWN << "You have slain the entio " << i->letra << enti::endl;
								enti::cout << enti::cend;
								a.erase(i);
							}
							hit = true;
						}
					}
					objectiverow--;
					aux--;
				}
			}
			else if (num == enti::InputKey::s || num == enti::InputKey::S)
			{
				int objectiverow = it->row + 3;
				int objectivecol = it->colum;
				if (objectiverow < mymapa.max_rows)
				{
					int aux = 8;
					while (objectiverow > objectiverow + 7 && mymapa.map[objectiverow][objectivecol] != 'X')
					{
						for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
						{
							if (objectiverow == i->row && objectivecol == i->colum && !hit)
							{
								i->life -= aux;
								enti::cout << enti::Color::BROWN << "The damage done to the entio " << i->letra << " is " << aux << " current entio life " << i->life << enti::endl;
								enti::cout << enti::cend;
								if (i->life == 0)
								{
									enti::cout << enti::Color::BROWN << "You have slain the entio " << i->letra << enti::endl;
									enti::cout << enti::cend;
									a.erase(i);
								}
								hit = true;
							}
						}
						objectiverow++;
						aux--;
					}
				}
			}
			else if (num == enti::InputKey::a || num == enti::InputKey::A)
			{
				int objectiverow = it->row;
				int objectivecol = it->colum-3;
				if (objectiverow > 0)
				{
					int aux = 8;
					while (objectiverow > objectiverow - 7 && mymapa.map[objectiverow][objectivecol] != 'X')
					{
						for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
						{
							if (objectiverow == i->row && objectivecol == i->colum && !hit)
							{
								i->life -= aux;
								enti::cout << enti::Color::BROWN << "The damage done to the entio " << i->letra << " is " << aux << " current entio life " << i->life << enti::endl;
								enti::cout << enti::cend;
								if (i->life == 0)
								{
									enti::cout << enti::Color::BROWN << "You have slain the entio" << i->letra << enti::endl;
									enti::cout << enti::cend;
									a.erase(i);
								}
								hit = true;
							}
						}
						objectiverow--;
						aux--;
					}
				}
			}
			else if (num == enti::InputKey::d || num == enti::InputKey::D)
			{
				int objectiverow = it->row;
				int objectivecol = it->colum+3;
				if (objectiverow < mymapa.max_cols)
				{
					int aux = 8;
					while (objectiverow > objectiverow + 7 && mymapa.map[objectiverow][objectivecol] != 'X')
					{
						for (std::list<entio>::iterator i = a.begin(); i != a.end(); i++)
						{
							if (objectiverow == i->row && objectivecol == i->colum && !hit)
							{
								i->life -= aux;
								enti::cout << enti::Color::BROWN << "The damage done to the entio " << i->letra << " is " << aux << " current entio life " << i->life << enti::endl;
								enti::cout << enti::cend;
								if (i->life == 0)
								{
									enti::cout << enti::Color::BROWN << "You have slain the entio " << i->letra << enti::endl;
									enti::cout << enti::cend;
									a.erase(i);
								}
								hit = true;
							}
						}
						objectiverow++;
						aux--;
					}
				}
			}
		}
		it->arrows--;
		movements--;
		enti::cout << enti::cend;
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

void Player::Input(enti::InputKey a, Player b)
{
	switch (a)
	{
	case enti::InputKey::NONE:
		break;
	case enti::InputKey::ENTER:
		changeentio();
		break;
	case enti::InputKey::SPACEBAR:
		ataque(b.entios);
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
	it2 = entios.end();
	it2--;
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

