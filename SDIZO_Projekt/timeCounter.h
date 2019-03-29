#pragma once
#include <iostream>
using namespace std;

class timeCounter
{
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
	double sumOfTimes = 0.0;
	int numberOfMeasurements = 0;
	void InitCounter();
	void EndSingleMeasurement();
	void StartNextMeasurement();
	double Summarize();
public:
	timeCounter();
	~timeCounter();
	void Start(int num, int stepSize, int numOfSearches, int numOfReps, ostream & stream);
};

