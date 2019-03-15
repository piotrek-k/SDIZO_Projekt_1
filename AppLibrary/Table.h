#pragma once
#include <string>
#include "Structure.h"
using namespace std;

class Table: public Structure
{
	int *tab;
	int count; //zadeklarowana w pliku ilość elementów w tablicy
public:

	Table();
	Table(int length, int * arr);

	~Table();

	void loadFromFile(string FileName);

	bool findValue(int val);

	void addElement(int index, int value);

	void removeElement(int index);

	void display();

	void generateRandom(int size);

	int getDeclaredSize();

	int getValueAtIndex(int index);

};