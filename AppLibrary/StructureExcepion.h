#pragma once
#include <exception>
#include <string>
using namespace std;

class StructureExcepion : public exception
{
	char* errorMessage;
public:
	StructureExcepion(char* message);
	virtual const char* what() const throw();
};

