#include "Input.inl.hh"
#include "Renderer.hh"
#include <iostream>
#include <list>
#include "Mapa.h"
#include "Player.h"

void main()
{
	bool isp1 = true;
	Mapa a;
	Player p1(isp1, a);
	Player p2(!isp1, a);
	bool endgame=false;
	bool p1turn = true;
	bool startturn = true;
	enti::cout << enti::Color::YELLOW << "CLASH OF ENTIOS" << enti::endl;
	enti::cout << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each player has 6 entios." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Use WASD to move each entio." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Use Z to undo a movement." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each entio has two weapons: 1 sword and 1 bow." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Press SPACEBAR to use a weapon." << enti::endl;
	enti::cout << enti::Color::WHITE << "- The sword can instantly kill an enemy if it is placed in a cell next door." << enti::endl;
	enti::cout << enti::Color::WHITE << "- The bow can damage an enemy within a maximum distance of 10 cells." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each character has only 10 arrows." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each turn the less fatigued entio will play first." << enti::endl;
	enti::cout << enti::Color::WHITE << "- To play with the next entio press ENTER." << enti::endl;
	enti::cout << enti::Color::WHITE << "- Each player can do 10 of these actions per turn." << enti::endl;
	enti::cout << enti::endl;
	enti::cout << enti::Color::LIGHTMAGENTA << "Press any key to begin the game!" << enti::endl;
	enti::cout << enti::cend;
	enti::systemPause();
	a.print(p1turn, p1.it->letra);
	enti::cout << enti::cend;
	while (!endgame)
	{
		if (p1turn)
		{
			if (startturn)
			{
				p1.reorder();
				startturn = false;
			}
			enti::InputKey num;
		
			num = enti::getInputKey();
			while (num == enti::InputKey::NONE)
			{
				num = enti::getInputKey();
			}
			p1.Input(num, p2,p1turn);
			a.print(p1turn, p1.it->letra);
			enti::cout << enti::cend;
			if (p1.movements == 0)
			{
				p1turn = false;
				startturn = true;
				p1.movements = 10;
				a.print(p1turn, p2.it->letra);
				enti::cout << enti::cend;
			}
			
		}
		else {
			if (startturn){
				p2.reorder();
				startturn = false;
			}
		enti::InputKey num;
		num = enti::getInputKey();
		while (num == enti::InputKey::NONE)
		{
			num = enti::getInputKey();
		}
		p2.Input(num, p1,p1turn);
		a.print(p1turn, p2.it->letra);
		enti::cout << enti::cend;
		if (p2.movements == 0)
		{
			p1turn = true;
			startturn = true;
			p2.movements = 10;
			a.print(p1turn, p1.it->letra);
			enti::cout << enti::cend;
		}
		}
	}
}