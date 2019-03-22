#include<string>
using namespace std;
#pragma once
class Heap
{
	int *tab;
	int count; //zadeklarowana w pliku iloœæ elementów w tablicy
	bool searchFromIndex(int val, int index); //funkcja pomocnicza do findValue
public:
	void loadFromFile(std::string FileName);

	int getIndexOfParent(int index);
	int getLeftChildIndex(int index);
	int getRightChildIndex(int index);

	void populateFromArray(int * arr, int size);
	void buildHeap();
	void heapify(int index);

	bool findValue(int val);
	void addElement(int key);
	void removeElementAtIndex(int index);
	std::string convertToString();
	void generateRandom(int size);
	int* toArray();
	void display(ostream & stream);

	int getDeclaredSize();
	void changeDeclaredSize(int newCount);
};

