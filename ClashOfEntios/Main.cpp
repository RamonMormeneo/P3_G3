#include "Input.inl.hh"
#include "Renderer.hh"
#include <iostream>
#include <list>
#include "Mapa.h"
#include "Player.h"

void main()
{

	Mapa a;
	Player p1(true, a);
	Player p2(false, a);
	a.print(true, p1.it->letra);
	p1.it++;
	a.print(true, p1.it->letra);

}