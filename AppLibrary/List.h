#pragma once
#include "Structure.h"
#include "ListMember.h"
class List :
	public Structure
{
	int count = 0;
	ListMember* firstValue = NULL;
public:
	virtual void loadFromFile(std::string FileName);
	virtual bool findValue(int val);
	void addElementAtIndex(int index, int value);
	virtual void removeElementByValue(int value);
	void addElement(int value);
	void display(std::ostream & stream);
	virtual void generateRandom(int size);
	int* toArray();
	int getDeclaredSize();
	ListMember* getFirstValue();
};

