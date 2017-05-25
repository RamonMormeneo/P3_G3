#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Renderer.hh"
class Mapa
{
private:
	
public:
	const int max_cols{ 74 };
	const int max_rows{ 36 };
	const int map_total{ max_rows *max_cols };
	char **map;
	void print(bool p1turn,char entio);
	void modificar(int row, int col, char simbol);
	Mapa();
	~Mapa();
};

