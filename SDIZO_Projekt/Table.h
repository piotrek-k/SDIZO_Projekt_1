#pragma once
#include <string>
using namespace std;

class Table
{
	int *tab;
	int cnt; //ilo�� element�w w tablicy
public:

	Table();

	~Table();

	int loadFromFile(string FileName);

	bool IsValueInTable(int val);

	void addValue(int index, int value);

	void deleteFromTable(int index);

	void display();

	void generateTable(int size);

};