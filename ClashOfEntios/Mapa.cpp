#include "Mapa.h"



void Mapa::print(bool p1turn, char entio)
{
	for (int i = 0; i < max_rows; i++)
	{
		for (int j = 0; j < max_cols; j++)
		{
			
			switch (map[i][j])
			{
			case 'X':
					enti::cout << enti::Color::LIGHTRED;
					break;
			case 'O':
				enti::cout << enti::Color::LIGHTCYAN;
				break;
			case ':':
				enti::cout << enti::Color::LIGHTGREEN;
				break;
			default:
				enti::cout << enti::Color::WHITE;
				if (p1turn == true)
				{
					if (map[i][j] >= 'A'&& map[i][j] <= 'F')
					{
						enti::cout << enti::Color::YELLOW;
					}
				}
				else
				{
					if (map[i][j] >= '1'&& map[i][j] <= '6')
					{
						enti::cout << enti::Color::YELLOW;
					}
				}
				if (map[i][j] == entio)
				{
					enti::cout << enti::Color::LIGHTMAGENTA;
				}
				break;
				
			}
			enti::cout << map[i][j]<< ' ';
		}
		enti::cout << enti::endl;
	}
	enti::cout << enti::cend;
}

void Mapa::modificar(int row, int col, char simbol)
{
	map[row][col] = simbol;
}

Mapa::Mapa()
{
	map = new char*[max_rows];
	const int TOTAL_MAP{ 74 };
	int m[TOTAL_MAP];
	std::ifstream myFile1("default.cfg");
	char line[TOTAL_MAP];
	int aux=0;
	while (myFile1.getline(line, TOTAL_MAP))
	{	
		map[aux] = new char[max_cols];
		for (int j = 0; j < max_cols; j++)
		{
			map[aux][j] = line[j];
		}
		aux++;
	}
	myFile1.close();

}


Mapa::~Mapa()
{
	for (int i = 0; i <max_rows; i++)
	{
		delete[]map[i];
	}
	delete[]map;
}
