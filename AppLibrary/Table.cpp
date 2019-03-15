#include "stdafx.h"
#include "Table.h"
#include <fstream>
#include <sstream>

using namespace std;

Table::Table()
{
}


Table::~Table()
{
}

void Table::loadFromFile(string FileName)
{
	int inputValueIndex = -1;
	string line;
	ifstream myfile(FileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int number = stoi(line);
			/*std::istringstream iss(line);
			iss >> number;
			if (!iss.good()) {
				throw "Konwersja tekstu z pliku do wartoœci int nie powiod³a siê";
			}*/

			if (inputValueIndex == -1) {
				this->count = number;
				this->tab = new int[this->count];
			}
			else {
				this->tab[inputValueIndex] = number;
			}
			inputValueIndex++;
		}
		myfile.close();
	}
	else {
		throw "Wyst¹pi³ problem z wczytaniem danych z pliku";
	}
}

bool Table::IsValueInTable(int val)
{
	return false;
}

void Table::addValue(int index, int value)
{
}

void Table::deleteFromTable(int index)
{
}

void Table::display()
{
}

void Table::generateTable(int size)
{
}

int Table::getDeclaredSize()
{
	return this->count;
}

int Table::getValueAtIndex(int index)
{
	return this->tab[index];
}
