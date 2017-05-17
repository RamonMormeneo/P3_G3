#include "Mapa.h"



Mapa::Mapa()
{
	map = new char*[max_rows];

	std::ifstream myFile1("default.cfg");
	
	for (int i = 0; i < max_rows; i++)
	{
		
	}
}


Mapa::~Mapa()
{
}
