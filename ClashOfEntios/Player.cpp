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

void Player::ataque(Player &a,bool turn)
{
	enti::InputKey num;
	mymapa.print(turn,it->letra);
	enti::cout << enti::Color::MAGENTA << "1 - Sword" << enti::endl;
	enti::cout << enti::Color::MAGENTA << "2 - Bow" << enti::endl;
	enti::cout<< enti::cend;
	num = enti::getInputKey();
	while (num == enti::InputKey::NONE)
	{
		num = enti::getInputKey();
	}
	if (num== enti::InputKey::NUM1)
	{
		mymapa.print(turn, it->letra);
		enti::cout << enti::Color::MAGENTA << "1 - UP" << enti::endl;
		enti::cout << enti::Color::MAGENTA << "2 - DOWN" << enti::endl;
		enti::cout << enti::Color::MAGENTA << "3 - LEFT" << enti::endl;
		enti::cout << enti::Color::MAGENTA << "4 - RIGTH" << enti::endl;
		enti::cout << enti::cend;
		num = enti::getInputKey();
		while (num == enti::InputKey::NONE)
		{
			num = enti::getInputKey();
		}
		if (num == enti::InputKey::NUM1)
		{
			int objectiverow = it->row - 1;
			int objectivecol = it->colum;
			bool hit = false;
			std::list<entio>::iterator enemy = a.entios.begin();
			while (!hit)
			{
				if (objectiverow == enemy->row&&objectivecol == enemy->colum)
				{
					std::list <entio>::iterator aux = enemy;
					mymapa.print(turn, it->letra);
					enti::cout << enti::Color::MAGENTA << "Entio Killed:"<< enemy->letra << enti::endl;
					enemy++;
					mymapa.modificar(objectiverow, objectivecol, aux->last_char);
					a.entios.erase(aux);
					hit = true;
				}
				else
				{
					enemy++;
				}
				if (enemy == a.entios.end())
				{
					
					if (!hit)
					{
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "You Failed" << enti::endl;
					}
					hit = true;
				}
			}
		}
		if (num == enti::InputKey::NUM2)
		{
			int objectiverow = it->row + 1;
			int objectivecol = it->colum;
			bool hit = false;
			std::list<entio>::iterator enemy = a.entios.begin();
			while (!hit)
			{
				if (objectiverow == enemy->row&&objectivecol == enemy->colum)
				{
					std::list <entio>::iterator aux = enemy;
					mymapa.print(turn, it->letra);
					enti::cout << enti::Color::MAGENTA << "Entio Killed:" << enemy->letra << enti::endl;
					enemy++;
					mymapa.modificar(objectiverow, objectivecol, aux->last_char);
					a.entios.erase(aux);
					hit = true;
				}
				else
				{
					enemy++;
				}
				if (enemy == a.entios.end())
				{
					
					if (!hit)
					{
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "You Failed" << enti::endl;
					}
					hit = true;
				}
			}
		}
		if (num == enti::InputKey::NUM3)
		{
			int objectiverow = it->row;
			int objectivecol = it->colum-1;
			bool hit = false;
			std::list<entio>::iterator enemy = a.entios.begin();
			while (!hit)
			{
				if (objectiverow == enemy->row&&objectivecol == enemy->colum)
				{
					std::list <entio>::iterator aux = enemy;
					mymapa.print(turn, it->letra);
					enti::cout << enti::Color::MAGENTA << "Entio Killed:" << enemy->letra << enti::endl;
					enemy++;
					mymapa.modificar(objectiverow, objectivecol, aux->last_char);
					a.entios.erase(aux);
					hit = true;
				}
				else
				{
					enemy++;
				}
				if (enemy == a.entios.end())
				{
					
					if (!hit)
					{
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "You Failed" << enti::endl;
					}
					hit = true;
				}
			}
		}
		if (num == enti::InputKey::NUM4)
		{
			int objectiverow = it->row;
			int objectivecol = it->colum+1;
			bool hit = false;
			std::list<entio>::iterator enemy = a.entios.begin();
			while (!hit)
			{
				if (objectiverow == enemy->row&&objectivecol == enemy->colum)
				{
					std::list <entio>::iterator aux = enemy;
					mymapa.print(turn, it->letra);
					enti::cout << enti::Color::MAGENTA << "Entio Killed:" << enemy->letra << enti::endl;
					enemy++;
					mymapa.modificar(objectiverow, objectivecol, aux->last_char);
					a.entios.erase(aux);
					hit = true;
				}
				else
				{
					enemy++;
				}
				if (enemy == a.entios.end())
				{
					if (!hit)
					{
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "You Failed" << enti::endl;
					}
					hit = true;
				}
			}
		}
		movements--;
	}
	else if (num == enti::InputKey::NUM2 && it->arrows>0)
	{
		mymapa.print(turn, it->letra);
		enti::cout << enti::Color::MAGENTA << "1 - UP" << enti::endl;
		enti::cout << enti::Color::MAGENTA << "2 - DOWN" << enti::endl;
		enti::cout << enti::Color::MAGENTA << "3 - LEFT" << enti::endl;
		enti::cout << enti::Color::MAGENTA << "4 - RIGTH" << enti::endl;
		enti::cout << enti::cend;
		num = enti::getInputKey();
		while (num == enti::InputKey::NONE)
		{
			num = enti::getInputKey();
		}
		if (num == enti::InputKey::NUM1)
		{
			int dmg = 8;
			bool end = false;
			int pos = 3;
			int maxdistance = 10;
			int objectiverow = it->row - pos;
			int objectivecol = it->colum;
			if (objectiverow > 0)
			{
				while (pos <= maxdistance && !end)
				{
					bool hit = false;
					int objectiverow = it->row - pos;
					int objectivecol = it->colum;
					std::list<entio>::iterator enemy = a.entios.begin();
					if (mymapa.map[objectiverow][objectivecol] == 'X')
					{
						hit = true;
						end = true;
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "YOU MISS" << enemy->letra << enti::endl;
					}
					while (!hit)
					{
						if (objectiverow == enemy->row&&objectivecol == enemy->colum)
						{
							mymapa.print(turn, it->letra);
							enti::cout << enti::Color::MAGENTA << "HIT ENTIO" << enemy->letra << enti::endl;
							enti::cout << enti::Color::MAGENTA << "DMG" << dmg << enti::endl;
							hit = true;
							end = true;
							if (enemy->life <= 0)
							{
								std::list <entio>::iterator aux = enemy;
								mymapa.print(turn, it->letra);
								enti::cout << enti::Color::MAGENTA << "Entio Killed:" << enti::endl;
								enemy++;
								mymapa.modificar(objectiverow, objectivecol, aux->last_char);
								a.entios.erase(aux);
							}
						}
						else
						{
							enemy++;
						}
						if (enemy == a.entios.end())
						{
							hit = false;
						}
					}
					pos++;
					dmg--;
				}
			}
			if (!end)
			{
				enti::cout << enti::Color::MAGENTA << "YOU MISS" << enti::endl;
			}
		}
		if (num == enti::InputKey::NUM2)
		{
			int dmg = 8;
			bool end = false;
			int pos = 3;
			int maxdistance = 10;
			int objectiverow = it->row + pos;
			int objectivecol = it->colum;
			if (objectiverow < mymapa.max_rows)
			{
				while (pos <= maxdistance && !end)
				{
					bool hit = false;
					int objectiverow = it->row + pos;
					int objectivecol = it->colum;
					std::list<entio>::iterator enemy = a.entios.begin();
					if (mymapa.map[objectiverow][objectivecol] == 'X')
					{
						hit = true;
						end = true;
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "YOU MISS" << enemy->letra << enti::endl;
					}
					while (!hit)
					{
						if (objectiverow == enemy->row&&objectivecol == enemy->colum)
						{
							mymapa.print(turn, it->letra);
							enti::cout << enti::Color::MAGENTA << "HIT ENTIO" << enemy->letra << enti::endl;
							enti::cout << enti::Color::MAGENTA << "DMG" << dmg << enti::endl;
							hit = true;
							end = true;
							if (enemy->life <= 0)
							{
								std::list <entio>::iterator aux = enemy;
								mymapa.print(turn, it->letra);
								enti::cout << enti::Color::MAGENTA << "Entio Killed:" << enti::endl;
								enemy++;
								mymapa.modificar(objectiverow, objectivecol, aux->last_char);
								a.entios.erase(aux);
							}
						}
						else
						{
							enemy++;
						}
						if (enemy == a.entios.end())
						{
							hit = false;
						}
					}
					pos++;
					dmg--;
				}
			}
			if (!end)
			{
				enti::cout << enti::Color::MAGENTA << "YOU MISS" << enti::endl;
			}
		}
		if (num == enti::InputKey::NUM3)
		{
			int dmg = 8;
			bool end = false;
			int pos = 3;
			int maxdistance = 10;
			int objectiverow = it->row;
			int objectivecol = it->colum-pos;
			if (objectivecol > 0)
			{
				while (pos <= maxdistance && !end)
				{
					bool hit = false;
					int objectiverow = it->row;
					int objectivecol = it->colum - pos;
					std::list<entio>::iterator enemy = a.entios.begin();
					if (mymapa.map[objectiverow][objectivecol] == 'X')
					{
						hit = true;
						end = true;
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "YOU MISS" << enemy->letra << enti::endl;
					}
					while (!hit)
					{
						if (objectiverow == enemy->row&&objectivecol == enemy->colum)
						{
							mymapa.print(turn, it->letra);
							enti::cout << enti::Color::MAGENTA << "HIT ENTIO" << enemy->letra << enti::endl;
							enti::cout << enti::Color::MAGENTA << "DMG" << dmg << enti::endl;
							hit = true;
							end = true;
							if (enemy->life <= 0)
							{
								std::list <entio>::iterator aux = enemy;
								mymapa.print(turn, it->letra);
								enti::cout << enti::Color::MAGENTA << "Entio Killed:" << enti::endl;
								enemy++;
								mymapa.modificar(objectiverow, objectivecol, aux->last_char);
								a.entios.erase(aux);
							}
						}
						else
						{
							enemy++;
						}
						if (enemy == a.entios.end())
						{
							hit = false;
						}
					}
					pos++;
					dmg--;
				}
			}
			if (!end)
			{
				enti::cout << enti::Color::MAGENTA << "YOU MISS" << enti::endl;
			}
		}
		if (num == enti::InputKey::NUM4)
		{
			int dmg = 8;
			bool end = false;
			int pos = 3;
			int maxdistance = 10;
			int objectiverow = it->row;
			int objectivecol = it->colum + pos;
			if (objectivecol < mymapa.max_cols)
			{
				while (pos <= maxdistance && !end)
				{
					bool hit = false;
					int objectiverow = it->row;
					int objectivecol = it->colum + pos;
					std::list<entio>::iterator enemy = a.entios.begin();
					if (mymapa.map[objectiverow][objectivecol] == 'X')
					{
						hit = true;
						end = true;
						mymapa.print(turn, it->letra);
						enti::cout << enti::Color::MAGENTA << "YOU MISS" << enemy->letra << enti::endl;
					}
					while (!hit)
					{
						if (objectiverow == enemy->row&&objectivecol == enemy->colum)
						{
							mymapa.print(turn, it->letra);
							enti::cout << enti::Color::MAGENTA << "HIT ENTIO" << enemy->letra << enti::endl;
							enti::cout << enti::Color::MAGENTA << "DMG" << dmg << enti::endl;
							hit = true;
							end = true;
							if (enemy->life <= 0)
							{
								std::list <entio>::iterator aux = enemy;
								mymapa.print(turn, it->letra);
								enti::cout << enti::Color::MAGENTA << "Entio Killed:" << enti::endl;
								enemy++;
								mymapa.modificar(objectiverow, objectivecol, aux->last_char);
								a.entios.erase(aux);
							}
						}
						else
						{
							enemy++;
						}
						if (enemy == a.entios.end())
						{
							hit = false;
						}
					}
					pos++;
					dmg--;
				}
			}
			if (!end)
			{
				enti::cout << enti::Color::MAGENTA << "YOU MISS" << enti::endl;
			}
		}
		movements--;
		it->arrows--;
		enti::cout << enti::Color::MAGENTA << "ARROWS LEFT"<<it->arrows << enti::endl;
	}
	enti::cout << enti::cend;
	enti::systemPause();
}


void Player::controlX()
{
	if (moveforward == true && moveback ==false){

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
		

void Player::controlZ()
{

	if (moveback == true && moveforward==false){

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

	}
	
}

void Player::Move(enti::InputKey a)
{
	if (a == enti::InputKey::w || a == enti::InputKey::W)
	{
		if (mymapa.map[it->row - 1][it->colum] == '.' || mymapa.map[it->row - 1][it->colum] == ':')
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
		if (mymapa.map[it->row][it->colum - 1] == '.' || mymapa.map[it->row][it->colum - 1] == ':')
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
		if (mymapa.map[it->row + 1][it->colum] == '.' || mymapa.map[it->row + 1][it->colum] == ':')
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
		if (mymapa.map[it->row][it->colum + 1] == '.' || mymapa.map[it->row][it->colum + 1] == ':')
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

void Player::Input(enti::InputKey a, Player b, bool turn)
{
	switch (a)
	{
	case enti::InputKey::NONE:
		break;
	case enti::InputKey::ENTER:
		changeentio();
		break;
	case enti::InputKey::SPACEBAR:
		ataque(b,turn);
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
			controlZ();
		}
		else if ((a == enti::InputKey::x || a == enti::InputKey::X))
		{
			controlX();
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
			maspeque = false;
		}
		it2++;
	}
	it = entios.begin();
}


Player::~Player()
{
}

