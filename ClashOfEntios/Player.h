#pragma once
#include <list>
enum weapon
{

};
class Player
{
public:
	struct entio
	{
		int colum;
		int row;
		int life;
		int arrows = 10;
		char letra;
	};
	std::list <entio> c;
	Player();
	~Player();
};

