#pragma once
#include <string>
using namespace std;

class Table
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

	void display(ostream & stream);

	void generateRandom(int size);

	int getDeclaredSize();

	int getValueAtIndex(int index);

};