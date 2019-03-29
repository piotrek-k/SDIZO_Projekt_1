#include "pch.h"
#include "timeCounter.h"
#include <windows.h>
#include <iostream>

#include "../AppLibrary/Table.h"
#include "../AppLibrary/List.h"
#include "../AppLibrary/Heap.h"
#include "../AppLibrary/RBTree.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

timeCounter::timeCounter()
{
}


timeCounter::~timeCounter()
{
}

void timeCounter::InitCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;
	this->sumOfTimes = 0.0;
	this->numberOfMeasurements = 0;
}

void timeCounter::EndSingleMeasurement()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);

	this->numberOfMeasurements++;
	this->sumOfTimes += double(li.QuadPart - CounterStart) / PCFreq;
}

void timeCounter::StartNextMeasurement()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);

	CounterStart = li.QuadPart;
}

double timeCounter::Summarize()
{
	return this->sumOfTimes / (double)this->numberOfMeasurements;
}

void timeCounter::Start(int num, int stepSize, int numOfSearches, int numOfReps, ostream & stream)
{
	srand(time(NULL));
	List myList = List();
	Heap myHeap = Heap();
	RBTree myTree = RBTree();
	Table* myTab = new Table();
	for (int numOfElements = stepSize; numOfElements < num; numOfElements += stepSize) {
		//---------TABELA
		stream << "Tab " << numOfElements << "\t";
		// dodawanie
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myTab->addElementAtTheEnd(1);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";
		//usuwanie z poczatku
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			myTab->generateRandom(numOfElements, 10);
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myTab->removeElementAtTheEnd();
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << "\t";

		//usuwanie z konca
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			myTab->generateRandom(numOfElements, 10);
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myTab->removeElementAtTheBeginning();
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << "\t";

		//wyszukiwanie losowych
		myTab->generateRandom(numOfElements, 10);
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			for (int a = 0; a < numOfSearches; a++) {
				myTab->findValue(rand() % 10);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << "\t";
		stream << endl;
	}
}