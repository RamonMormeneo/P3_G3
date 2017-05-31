#pragma once
#include <list>
#include "Mapa.h"
#include "Input.inl.hh"

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
		char last_char='.';
	};

	std::list <entio> entios;
	int movements=10;
	Mapa &mymapa;
	void reorder();
	void changeentio();
	void ataque(std::list <entio> a, bool turn);
	void controlZX();
	bool moveback;
	bool moveforward;
	void Move(enti::InputKey a);
	void Input(enti::InputKey a,Player b,bool turn);
	std::list<entio>::iterator it,it2;
	Player(bool letras, Mapa &a);
	~Player();
};

