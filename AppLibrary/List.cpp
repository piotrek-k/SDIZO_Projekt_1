#include "stdafx.h"
#include "List.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ListMember.h"

using namespace std;

void List::loadFromFile(std::string FileName)
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
				//this->tab = new int[this->count];
			}
			else {
				//this->tab[inputValueIndex] = number;
				this->addElement(0);
			}
			inputValueIndex++;
		}
		myfile.close();
	}
	else {
		throw "Wyst¹pi³ problem z wczytaniem danych z pliku";
	}
}

bool List::findValue(int val)
{
	return false;
}

void List::addElementAtIndex(int index, int value)
{
}

void List::removeElementAtIndex(int index)
{
}

void List::addElement(int value)
{
	ListMember* newElem = (ListMember*)malloc(sizeof(struct ListMember));
	newElem->value = value;
	if (firstValue != NULL) {
		firstValue->nextValue = newElem;
		newElem->prevValue = firstValue;
	}
	firstValue = newElem;

	count++;
}

void List::display()
{
}

void List::generateRandom(int size)
{
}

int* List::toArray()
{
	int* newArr = new int[count];
	ListMember* lm = firstValue;
	for (int a = 0; a < count; a++) {
		newArr[a] = lm->value;
		lm = lm->prevValue;
	}
	return newArr;
}

int List::getDeclaredSize()
{
	return count;
}
