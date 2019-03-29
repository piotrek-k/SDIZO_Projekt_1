#include "stdafx.h"
#include "Table.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

Table::Table()
{
}

/// <summary>
/// Konwertuje tablicê jêzyka C++ na tablicê zaimplementowan¹ w programie
/// </summary>
/// <param name="length"></param>
/// <param name="arr"></param>
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

/// <summary>
/// Generuje tablicê na podstawie danych z pliku
/// </summary>
/// <param name="FileName"></param>
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

/// <summary>
/// Szuka wartoœci w tablicy
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
bool Table::findValue(int val)
{
	for (int a = 0; a < getDeclaredSize(); a++) {
		if (tab[a] == val) {
			return true;
		}
	}
	return false;
}

/// <summary>
/// Dodaje element do tablicy. W tym celu dynamicznie generuje now¹ tablicê i kopiuje dane z poprzedniej.
/// </summary>
/// <param name="index"></param>
/// <param name="value"></param>
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
	delete tab;
	tab = newtab;
}

void Table::addElementAtBeginning(int value)
{
	addElement(0, value);
}

void Table::addElementAtTheEnd(int value)
{
	addElement(count, value);
}

/// <summary>
/// Usuwa element z tablicy
/// </summary>
/// <param name="index"></param>
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

void Table::removeElementAtTheEnd()
{
	removeElement(count - 1);
}

void Table::removeElementAtTheBeginning()
{
	removeElement(0);
}

/// <summary>
/// Przekazuje dane o tablicy na podany strumieñ
/// </summary>
/// <param name="stream"></param>
void Table::display(ostream& stream)
{
	stream << "Wyswietlanie tablicy. Zadeklarowana wielkosc: " << getDeclaredSize() << endl;
	for (int a = 0; a < getDeclaredSize(); a++) {
		stream << tab[a] << " ";
	}
}

/// <summary>
/// Generuje losowe wartoœci do tablicy
/// </summary>
/// <param name="size"></param>
void Table::generateRandom(int numberOfElements, int range)
{
	srand(time(NULL));

	delete tab;

	tab = new int[numberOfElements];
	count = numberOfElements;

	for (int a = 0; a < numberOfElements; a++) {
		tab[a] = rand() % range;
	}
}

/// <summary>
/// Zwraca wielkoœæ tablicy. Istnieje mo¿liwoœæ ¿e nie bêdzie poprawna jeœli u¿ytkownik poda b³êdny rozmiar tablicy.
/// </summary>
/// <returns></returns>
int Table::getDeclaredSize()
{
	return this->count;
}

/// <summary>
/// Zwraca wartoœæ elementu na podanej pozycji
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
int Table::getValueAtIndex(int index)
{
	return this->tab[index];
}
