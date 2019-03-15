#pragma once
#include "Structure.h"
#include "ListMember.h"
class List :
	public Structure
{
	int count;
	ListMember* firstValue = NULL;
public:
	virtual void loadFromFile(std::string FileName);
	virtual bool findValue(int val);
	void addElementAtIndex(int index, int value);
	virtual void removeElementByValue(int value);
	void addElement(int value);
	virtual void display();
	virtual void generateRandom(int size);
	int* toArray();
	int getDeclaredSize();
	ListMember* getFirstValue();
};

