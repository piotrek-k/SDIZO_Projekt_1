#include "stdafx.h"
#include "Heap.h"
#include <string>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

/// <summary>
/// Generuje kopiec z danych zwartych w pliku
/// </summary>
/// <param name="FileName">�cie�ka do pliku</param>
void Heap::loadFromFile(std::string FileName)
{
	clearHeap();

	string line;
	ifstream myfile(FileName);
	bool firstLine = true;
	try {
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				int number = stoi(line);
				if (firstLine) {
					firstLine = false;
					//count = number;
				}
				else {
					this->addElement(number);
				}
			}
			myfile.close();
		}
		else {
			throw exception("Wystapil problem z otworzeniem pliku o podanej nazwie");
		}
	}
	catch (std::invalid_argument& e) {
		return;
	}
	catch (const exception& e) {
		throw exception("Wystapil problem z wczytaniem danych z pliku");
	}
}

/// <summary>
/// Zwraca numer indeksu rodzica w�z�a o podanym indeksie
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
int Heap::getIndexOfParent(int index)
{
	int x = floor((index - 1) / 2);
	return x;
}

/// <summary>
/// Zwraca numer indeksu lewego potomka w�z�a
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
int Heap::getLeftChildIndex(int index)
{
	return 2 * index + 1;
}

/// <summary>
/// Zwraca numer indeksu prawego potomka w�z�a
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
int Heap::getRightChildIndex(int index)
{
	return 2 * index + 2;
}

/// <summary>
/// Generuje kopiec na podstawie podanej tablicy
/// </summary>
/// <param name="arr">tablica bazowa</param>
/// <param name="size">wielko�� podanej tablicy</param>
void Heap::populateFromArray(int * arr, int size)
{
	this->tab = arr;
	this->count = size;
	this->buildHeap();
}

/// <summary>
/// przywr�� w�asno�� kopca
/// </summary>
void Heap::buildHeap()
{
	for (int x = floor(this->getDeclaredSize() / 2) - 1; x >= 0; x--) {
		this->heapify(x);
	}
}

/// <summary>
/// sprawd� poprawno�� po�o�enia w�z�a o podanym indeksie
/// </summary>
/// <param name="index"></param>
void Heap::heapify(int index)
{
	int l = this->getLeftChildIndex(index);
	int r = this->getRightChildIndex(index);
	int largest = 0;

	if (l <= this->getDeclaredSize() && this->tab[l] > this->tab[index]) {
		largest = l;
	}
	else {
		largest = index;
	}

	if (r <= this->getDeclaredSize() && this->tab[r] > this->tab[largest]) {
		largest = r;
	}

	if (largest != index) {
		int t = this->tab[index];
		this->tab[index] = this->tab[largest];
		this->tab[largest] = t;
		this->heapify(largest);
	}
}

/// <summary>
/// sprawd� czy element jest poprawnie u�o�ony wzgl�dem parenta.
/// je�li nie, zamie� ich warto�ci
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
void Heap::validateParent(int index)
{
	int indexOfParent = this->getIndexOfParent(index);
	int elemValue = this->tab[index];
	int parentValue = this->tab[indexOfParent];
	if (indexOfParent >= 0 && indexOfParent != index && elemValue > parentValue) {
		this->tab[index] = parentValue;
		this->tab[indexOfParent] = elemValue;
		validateParent(indexOfParent);
	}
}

/// <summary>
/// sprawd� czy warto�� jest w kopcu
/// </summary>
/// <param name="val"></param>
/// <returns></returns>
bool Heap::findValue(int val)
{
	return this->searchFromIndex(val, 0);
}

int Heap::getValueAtIndex(int index)
{
	if (!indexIsValid(index)) {
		return 0;
	}
	return tab[index];
}

bool Heap::indexIsValid(int index)
{
	if (index < 0 || index >= getDeclaredSize()) {
		return false;
	}
	return true;
}

/// <summary>
/// Funkcja pomocnicza do findValue
/// </summary>
/// <param name="val"></param>
/// <param name="index"></param>
/// <returns></returns>
bool Heap::searchFromIndex(int val, int index)
{
	if (index >= this->getDeclaredSize()) {
		return false;
	}

	if (this->tab[index] == val) {
		return true;
	}
	if (this->tab[index] < val) {
		return false;
	}

	return this->searchFromIndex(val, getLeftChildIndex(index)) || this->searchFromIndex(val, getRightChildIndex(index));
}

/// <summary>
/// Dodaje element do kopca
/// </summary>
/// <param name="key"></param>
void Heap::addElement(int key)
{
	int i = getDeclaredSize();
	this->changeDeclaredSize(i + 1);
	//tab[this->getDeclaredSize()] = key;

	while (i > 0 && this->tab[getIndexOfParent(i)] < key) {
		tab[i] = tab[getIndexOfParent(i)];
		i = getIndexOfParent(i);
	}

	tab[i] = key;
}

/// <summary>
/// Usuwa element o podanym indeksie z kopca
/// </summary>
/// <param name="index"></param>
void Heap::removeElementAtIndex(int index)
{
	if (index >= getDeclaredSize()) {
		throw exception("Podany indeks jest poza zakresem tablicy");
	}
	tab[index] = tab[getDeclaredSize() - 1];
	changeDeclaredSize(getDeclaredSize() - 1);
	heapify(index);
	validateParent(index);
}

void Heap::removeElementByValue(int value)
{
	int foundIndex = -1;
	for (int a = 0; a < this->getDeclaredSize(); a++) {
		if (tab[a] == value) {
			foundIndex = a;
			break;
		}
	}

	if (foundIndex != -1) {
		this->removeElementAtIndex(foundIndex);
	}
	else {
		throw exception("Nie znaleziono podanej warto�ci");
	}
}

/// <summary>
/// Zwraca ci�g znak�w reprezentuj�cy kopiec
/// </summary>
/// <returns></returns>
string Heap::convertToString()
{
	string result;
	for (int a = 0; a < getDeclaredSize(); a++) {
		result += std::to_string(tab[a]) + " ";
	}
	return result;
}

/// <summary>
/// Generuje losowe warto�ci do kopca
/// </summary>
/// <param name="size"></param>
void Heap::generateRandom(int size, int range)
{
	clearHeap();
	srand(time(NULL));
	//int* newArray = new int[size];
	for (int a = 0; a < size; a++) {
		//newArray[a] = rand() % range;
		int newV = rand() % range;
		this->addElement(newV);
	}
	//this->populateFromArray(newArray, size);
}

/// <summary>
/// Zwraca tablic� odpowiadaj�c� strukturze kopca
/// </summary>
/// <returns></returns>
int * Heap::toArray()
{
	return tab;
}

/// <summary>
/// Przekazuje dane o kopcu na podany strumie�
/// </summary>
/// <param name="stream"></param>
void Heap::display(ostream & stream)
{
	stream << "Wyswietlanie kopca. Zadeklarowana wielkosc: " << getDeclaredSize() << endl;
	for (int a = 0; a < getDeclaredSize(); a++) {
		stream << tab[a] << " ";
	}
}

/// <summary>
/// Zwraca wielko�� kopca. Istnieje mo�liwo�� �e nie b�dzie poprawna je�li u�ytkownik poda b��dny rozmiar tablicy.
/// </summary>
/// <returns></returns>
int Heap::getDeclaredSize()
{
	return count;
}

/// <summary>
/// Zmienia wielko�� tablicy przechowuj�cej kopiec na podan�
/// </summary>
/// <param name="newCount"></param>
void Heap::changeDeclaredSize(int newCount)
{
	int* newTab = new int[newCount];
	int currentSize = getDeclaredSize();
	for (int a = 0; a < min(newCount, currentSize); a++) {
		newTab[a] = this->tab[a];
	}

	clearHeap();
	this->count = newCount;
	this->tab = newTab;
}

void Heap::clearHeap() {
	delete tab;
	tab = new int[1];
	count = 0;
}