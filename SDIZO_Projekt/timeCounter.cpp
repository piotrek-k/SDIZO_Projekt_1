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
	List* myList = new List();
	Heap* myHeap = new Heap();
	RBTree* myTree = new RBTree();
	Table* myTab = new Table();
	for (int numOfElements = stepSize; numOfElements < num; numOfElements += stepSize) {
		//---------TABELA
		myTab->clearTable();
		stream << "Tab \t " << numOfElements << " \t ";
		// dodawanie
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myTab->addElementAtTheEnd(1);
			}
			EndSingleMeasurement();
			myTab->clearTable();
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
			myTab->clearTable();
		}
		stream << Summarize() << " \t ";

		//usuwanie z konca
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			myTab->generateRandom(numOfElements, 10);
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myTab->removeElementAtTheBeginning();
			}
			EndSingleMeasurement();
			myTab->clearTable();
		}
		stream << Summarize() << " \t ";

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
		myTab->clearTable();
		stream << Summarize() << " \t ";
		stream << endl;
	}

	for (int numOfElements = stepSize; numOfElements < num; numOfElements += stepSize) {
		//---------LISTA
		myList = new List();
		stream << "List \t " << numOfElements << " \t ";
		// dodawanie
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myList->addElement(1);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";

		//wyszukiwanie losowych
		myList->generateRandom(numOfElements, 10);
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			for (int a = 0; a < numOfSearches; a++) {
				myList->findValue(rand() % 10);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";
		stream << endl;
		
		delete myList;
	}


	for (int numOfElements = stepSize; numOfElements < num; numOfElements += stepSize) {
		//---------KOPIEC
		//myHeap = new Heap();
		myHeap->clearHeap();
		stream << "Heap \t " << numOfElements << " \t ";
		// dodawanie
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			myHeap->generateRandom(numOfElements, 10);
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";
		//usuwanie z poczatku
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			myHeap->generateRandom(numOfElements, 10);
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myHeap->removeElementAtIndex(myHeap->getDeclaredSize() - 1);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";

		//usuwanie z konca
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			myHeap->generateRandom(numOfElements, 10);
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myHeap->removeElementAtIndex(0);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";

		//wyszukiwanie losowych
		myHeap->generateRandom(numOfElements, 10);
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			for (int a = 0; a < numOfSearches; a++) {
				myHeap->findValue(rand() % 10);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";
		stream << endl;

		//delete myHeap;
	}

	for (int numOfElements = stepSize; numOfElements < num; numOfElements += stepSize) {
		//---------Drzewo CC
		stream << "RBTree \t " << numOfElements << " \t ";
		// dodawanie
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			myTree->generateRandom(numOfElements, 10);
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";
		//usuwanie wartoœci rosn¹co
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			myTree = new RBTree();
			for (int a = 0; a < numOfElements; a++) {
				myTree->rbInsert(a);
			}
			StartNextMeasurement();
			for (int a = 0; a < numOfElements; a++) {
				myTree->removeElement(a);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";

		//wyszukiwanie losowych
		myTree->generateRandom(numOfElements, 10);
		InitCounter();
		for (int b = 0; b < numOfReps; b++) {
			StartNextMeasurement();
			for (int a = 0; a < numOfSearches; a++) {
				myTree->findValue(rand() % 10);
			}
			EndSingleMeasurement();
		}
		stream << Summarize() << " \t ";
		stream << endl;
	}
}