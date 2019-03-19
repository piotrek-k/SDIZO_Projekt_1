#include "stdafx.h"
#include "Table.h"
#include <fstream>
#include <sstream>
#include "StructureExcepion.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

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
		try {
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
		catch (const exception& e) {
			throw exception("Wystapil problem z wczytaniem danych z pliku");
		}
	}
	else {
		throw exception("Wystapil problem z otworzeniem pliku o podanej nazwie");
	}
}

bool Table::findValue(int val)
{
	for (int a = 0; a < getDeclaredSize(); a++) {
		if (tab[a] == val) {
			return true;
		}
	}
	return false;
}

void Table::addElement(int index, int value)
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

void Table::removeElement(int index)
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

void Table::display(ostream& stream)
{
	stream << "Wyswietlanie tablicy. Zadeklarowana wielkosc: " << getDeclaredSize() << endl;
	for (int a = 0; a < getDeclaredSize(); a++) {
		stream << tab[a] << " ";
	}
}

void Table::generateRandom(int numberOfElements)
{
	srand(time(NULL));

	tab = new int[numberOfElements];
	count = numberOfElements;

	for (int a = 0; a < numberOfElements; a++) {
		tab[a] = rand() % 150 - 50;
	}
}

int Table::getDeclaredSize()
{
	return this->count;
}

int Table::getValueAtIndex(int index)
{
	return this->tab[index];
}
