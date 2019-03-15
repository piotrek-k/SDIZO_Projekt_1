#pragma once
#include <string>
using namespace std;

class Table
{
	int *tab;
	int count; //zadeklarowana w pliku ilość elementów w tablicy
public:

	Table();

	~Table();

	void loadFromFile(string FileName);

	bool IsValueInTable(int val);

	void addValue(int index, int value);

	void deleteFromTable(int index);

	void display();

	void generateTable(int size);

	int getDeclaredSize();

	int getValueAtIndex(int index);

};