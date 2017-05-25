#pragma once
#include <list>
#include "Mapa.h"
class Player
{
public:
	struct entio
	{
		int colum;
		int row;
		int life=10;
		int arrows = 10;
		int fatiga=0;
		char letra;
		int last_col;
		int last_row;
	};
	std::list <entio> entios;
	int movements;
	Mapa &mymapa;
	std::list<entio>::iterator it;
	Player(bool letras, Mapa &a);
	~Player();
};

