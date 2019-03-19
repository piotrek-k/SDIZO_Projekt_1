#include "stdafx.h"
#include "List.h"
#include <string>
#include <iostream>
#include <fstream>
#include "ListMember.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void List::loadFromFile(std::string FileName)
{
	string line;
	ifstream myfile(FileName);
	bool firstLine = true;
	if (myfile.is_open())
	{
		try {
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
		catch (const exception& e) {
			throw exception("Wystapil problem z wczytaniem danych z pliku");
		}
	}
	else {
		throw exception("Wystapil problem z otworzeniem pliku o podanej nazwie");
	}
}

bool List::findValue(int val)
{
	ListMember* lm = firstValue;
	for (int a = count - 1; a >= 0; a--) {
		if (lm == NULL) {
			throw exception("�le zadeklarowana liczba element�w listy");
		}

		if (lm->value == val) {
			return true;
		}
		lm = lm->prevValue;
	}
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
	for (int a = 0; a < getDeclaredSize(); a++) {
		if (nextElem == NULL || nextElem == nullptr) {
			break;
		}

		if (nextElem->value == value) {
			if (nextElem->prevValue && nextElem->nextValue) {
				(nextElem->prevValue)->nextValue = nextElem->nextValue;
				(nextElem->nextValue)->prevValue = nextElem->prevValue;
			}
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
		firstValue->nextValue = newElem;
		newElem->prevValue = firstValue;
	}
	firstValue = newElem;

	count++;
}

void List::display(ostream& stream)
{
	ListMember* lm = firstValue;
	for (int a = count - 1; a >= 0; a--) {
		stream << lm->value << " ";
		lm = lm->prevValue;
	}
}

void List::generateRandom(int size)
{
	srand(time(NULL));

	ListMember newFirstValue = ListMember();
	newFirstValue.value = rand() % 150 - 50;
	firstValue = &newFirstValue;

	ListMember* lastValue = firstValue;
	for (int a = 0; a < size; a++) {
		ListMember newValue = ListMember();
		newFirstValue.value = rand() % 150 - 50;

		lastValue->prevValue = &newValue;
		newValue.nextValue = lastValue;

		lastValue = &newValue;
	}
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
