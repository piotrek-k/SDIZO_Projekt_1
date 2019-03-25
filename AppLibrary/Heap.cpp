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
/// <param name="FileName">œcie¿ka do pliku</param>
void Heap::loadFromFile(std::string FileName)
{
	string line;
	ifstream myfile(FileName);
	bool firstLine = true;
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
		throw "Wyst¹pi³ problem z wczytaniem danych z pliku";
	}
}

int Heap::getIndexOfParent(int index)
{
	int x = floor((index - 1) / 2);
	return x;
}

int Heap::getLeftChildIndex(int index)
{
	return 2*index+1;
}

int Heap::getRightChildIndex(int index)
{
	return 2*index+2;
}

void Heap::populateFromArray(int * arr, int size)
{
	this->tab = arr;
	this->count = size;
	this->buildHeap();
}

void Heap::buildHeap()
{
	for (int x = floor(this->getDeclaredSize() / 2)-1; x >= 0; x--) {
		this->heapify(x);
	}
}

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

bool Heap::findValue(int val)
{
	return this->searchFromIndex(val, 0);
}

bool Heap::searchFromIndex(int val, int index)
{
	if (this->tab[index] == val) {
		return true;
	}
	if (this->tab[index] < val) {
		return false;
	}

	return this->searchFromIndex(val, getLeftChildIndex(index)) || this->searchFromIndex(val, getRightChildIndex(index));
}

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

void Heap::removeElementAtIndex(int index)
{
	tab[index] = tab[getDeclaredSize() - 1];
	changeDeclaredSize(getDeclaredSize() - 1);
	heapify(index);
}

string Heap::convertToString()
{
	string result;
	for (int a = 0; a < getDeclaredSize(); a++) {
		result += std::to_string(tab[a]) + " ";
	}
	return result;
}

void Heap::generateRandom(int size)
{
	srand(time(NULL));
	int* newArray = new int[size];
	for (int a = 0; a < size; a++) {
		newArray[a] = rand() % 150 - 50;
	}
	this->populateFromArray(newArray, size);
}

int * Heap::toArray()
{
	return tab;
}

void Heap::display(ostream & stream)
{
	stream << "Wyswietlanie kopca. Zadeklarowana wielkosc: " << getDeclaredSize() << endl;
	for (int a = 0; a < getDeclaredSize(); a++) {
		stream << tab[a] << " ";
	}
}

int Heap::getDeclaredSize()
{
	return count;
}

void Heap::changeDeclaredSize(int newCount)
{
	int* newTab = new int[newCount];
	int currentSize = getDeclaredSize();
	for (int a = 0; a < min(newCount, currentSize); a++) {
		newTab[a] = this->tab[a];
	}

	this->count = newCount;
	this->tab = newTab;
}
