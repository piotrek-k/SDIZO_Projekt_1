#pragma once
#include "ListMember.h"
#include <string>

using namespace std;

class List
{
	int count = 0;
	ListMember* firstValue = NULL;
public:
	virtual void loadFromFile(std::string FileName);
	virtual bool findValue(int val);
	void addElementAtIndex(int index, int value);
	virtual void removeElementByValue(int value);
	void addElementAsFirst(int value);
	void display(std::ostream & stream);
	virtual void generateRandom(int size, int range);
	int* toArray();
	int getDeclaredSize();
	ListMember* getFirstValue();
};

