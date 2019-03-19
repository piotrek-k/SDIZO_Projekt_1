#include "stdafx.h"
#include "StructureExcepion.h"
#include <string>

using namespace std;

StructureExcepion::StructureExcepion(char* message)
{
	errorMessage = message;
}

const char * StructureExcepion::what() const throw()
{
	return this->errorMessage;
}
