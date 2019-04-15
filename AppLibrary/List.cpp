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

	firstValue = nullptr;
	count = 0;

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
					this->addElementAsFirst(number);
				}
			}
			myfile.close();
		}
		catch (std::invalid_argument & e) {
			return;
		}
		catch (const exception & e) {
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
			throw exception("le zadeklarowana liczba elementów listy");
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
	if (index > this->getDeclaredSize()) {
		throw exception("Podany indeks jest poza zakresem listy");
	}
	int indexCounter = 0;
	ListMember* nextElem = this->firstValue;
	ListMember* lastElem = NULL;
	while (nextElem || indexCounter == this->getDeclaredSize()) {

		if (indexCounter == index) {
			ListMember* newElem = new ListMember();
			newElem->value = value;
			if (nextElem != NULL) {
				newElem->nextValue = nextElem->nextValue;
				newElem->prevValue = nextElem;
				if (nextElem->nextValue != NULL)
					(nextElem->nextValue)->prevValue = newElem;
				nextElem->nextValue = newElem;
			}

			if (indexCounter == this->getDeclaredSize()) {
				newElem->nextValue = lastElem;
				if (lastElem != NULL) {
					lastElem->prevValue = newElem;
				}
			}

			if (index == 0) {
				this->firstValue = newElem;
			}

			this->count++;
			return;
		}

		indexCounter++;
		lastElem = nextElem;
		if (nextElem != NULL && nextElem->prevValue != NULL) {
			nextElem = nextElem->prevValue;
		}
		else {
			nextElem = NULL;
		}
	}
}

void List::removeElementByValue(int value)
{
	ListMember* elem = this->firstValue;
	for (int a = 0; a < getDeclaredSize(); a++) {
		if (elem == NULL) {
			break;
		}

		if (elem->value == value) {
			if (elem->prevValue != nullptr && a != getDeclaredSize() - 1)
				elem->prevValue->nextValue = elem->nextValue;
			if (elem->prevValue != nullptr && a != 0)
				elem->nextValue->prevValue = elem->prevValue;

			if (elem == this->firstValue)
				this->firstValue = elem->prevValue;

			delete elem;
			this->count--;
			return;
		}
		elem = elem->prevValue;
	}
}

void List::addElementAsFirst(int value)
{
	ListMember* newElem = new ListMember();
	newElem->value = value;
	if (firstValue != NULL) {
		firstValue->nextValue = newElem;
		newElem->prevValue = firstValue;
	}
	firstValue = newElem;

	count++;
}

void List::display(ostream & stream)
{
	stream << "Wyswietlanie listy. Zadeklarowana wielkosc: " << getDeclaredSize() << endl;
	if (getDeclaredSize() > 0) {
		ListMember* lm = firstValue;
		stream << lm->value << " ";
		for (int a = 0; a < count - 1; a++) {
			lm = lm->prevValue;
			stream << lm->value << " ";
		}

		stream << endl;
		stream << lm->value << " ";
		for (int a = 0; a < count - 1; a++) {
			lm = lm->nextValue;
			stream << lm->value << " ";
		}
	}
}

void List::generateRandom(int size, int range)
{
	srand(time(NULL));

	ListMember* newFirstValue = new ListMember();
	newFirstValue->value = rand() % range;
	firstValue = newFirstValue;

	ListMember* lastValue = firstValue;
	for (int a = 0; a < size - 1; a++) {
		ListMember* newValue = new ListMember();
		newValue->value = rand() % range;

		lastValue->prevValue = newValue;
		newValue->nextValue = lastValue;

		lastValue = newValue;
	}

	count = size;
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

ListMember* List::getFirstValue()
{
	return firstValue;
}
