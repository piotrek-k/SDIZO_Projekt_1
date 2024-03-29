#include<string>
using namespace std;
#pragma once
class Heap
{
	int *tab;
	int count; //zadeklarowana w pliku ilo�� element�w w tablicy

	bool searchFromIndex(int val, int index); //funkcja pomocnicza do findValue

public:
	void loadFromFile(std::string FileName);

	int getIndexOfParent(int index);
	int getLeftChildIndex(int index);
	int getRightChildIndex(int index);

	void buildHeap();
	void heapify(int index);
	void validateParent(int index);

	void populateFromArray(int * arr, int size);
	void addElement(int key);
	void removeElementAtIndex(int index);
	void removeElementByValue(int value);
	void generateRandom(int size, int range);

	bool findValue(int val);
	int getValueAtIndex(int index);
	bool indexIsValid(int index);
	
	std::string convertToString();
	int* toArray();
	void display(ostream & stream);

	int getDeclaredSize();
	void changeDeclaredSize(int newCount);

	void clearHeap();
};

