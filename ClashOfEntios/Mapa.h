#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Mapa
{
private:
	const int max_cols{ 74 };
	const int max_rows{ 36 };
public:
	
	char **map;
	Mapa();
	~Mapa();
};

