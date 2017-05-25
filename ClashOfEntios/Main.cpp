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
	p1.it++;

}