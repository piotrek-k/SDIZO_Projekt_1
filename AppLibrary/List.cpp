#include "stdafx.h"
#include "List.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ListMember.h"

using namespace std;

void List::loadFromFile(std::string FileName)
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

bool List::findValue(int val)
{
	return false;
}

void List::addElementAtIndex(int index, int value)
{
	int indexCounter = this->count - 1;
	ListMember* nextElem = this->firstValue;
	while (nextElem) {
		if (nextElem == NULL || indexCounter < 0) {
			break;
		}

		if (indexCounter == index) {
			ListMember* newElem = (ListMember*)malloc(sizeof(struct ListMember));
			newElem->value = value;
			newElem->nextValue = nextElem;
			newElem->prevValue = nextElem->prevValue;
			if (nextElem->prevValue != NULL)
				(nextElem->prevValue)->nextValue = newElem;
			nextElem->prevValue = newElem;
			this->count++;
			return;
		}

		indexCounter--;
		nextElem = nextElem->prevValue;
	}
}

void List::removeElementByValue(int value)
{
	ListMember* nextElem = this->firstValue;
	while (nextElem) {
		if (nextElem == NULL) {
			break;
		}
		if (nextElem->value == value) {
			if (nextElem->prevValue)
				(nextElem->prevValue)->nextValue = nextElem->nextValue;
			if (nextElem->nextValue)
				(nextElem->nextValue)->prevValue = nextElem->prevValue;
			delete nextElem;
			this->count--;
			return;
		}
		nextElem = nextElem->prevValue;
	}
}

void List::addElement(int value)
{
	ListMember* newElem = (ListMember*)malloc(sizeof(struct ListMember));
	newElem->value = value;
	if (firstValue != NULL) {
		//newElem->key = (firstValue->key) + 1;
		firstValue->nextValue = newElem;
		newElem->prevValue = firstValue;
	}
	else {
		//newElem->key = 0;
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
	for (int a = count - 1; a >= 0; a--) {
		newArr[a] = lm->value;
		lm = lm->prevValue;
	}
	return newArr;
}

int List::getDeclaredSize()
{
	return count;
}

ListMember * List::getFirstValue()
{
	return firstValue;
}
