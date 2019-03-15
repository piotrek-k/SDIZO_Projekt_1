#include "stdafx.h"
#include "Table.h"
#include <fstream>
#include <sstream>

using namespace std;

Table::Table()
{
}

Table::Table(int length, int * arr)
{
	this->count = length;
	tab = new int[length];
	for (int i = 0; i < length; i++) {
		tab[i] = arr[i];
	}
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
	int newSize = this->getDeclaredSize() + 1;
	int* newtab = new int[newSize];
	int oldIndex = 0;
	for (int a = 0; a < newSize; a++) {
		if (index == a) {
			newtab[a] = value;
		}
		else {
			newtab[a] = tab[oldIndex];
			oldIndex++;
		}
	}
	this->count = newSize;

	tab = newtab;
}

void Table::deleteFromTable(int index)
{
	int newSize = this->getDeclaredSize() - 1;
	int* newtab = new int[newSize];
	int oldIndex = 0;
	for (int a = 0; a < newSize; a++) {
		if (index == a) {
			oldIndex++;
		}
		newtab[a] = tab[oldIndex];
		oldIndex++;
	}
	this->count = newSize;

	tab = newtab;
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
