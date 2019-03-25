#include "stdafx.h"
#include <stdlib.h>
#include "RBMember.h"

using namespace std;

RBMember::RBMember()
{
}

bool RBMember::isNotNull()
{
	return state == Initialized;
}

bool RBMember::isNull()
{
	return state != Initialized;
}

/// <summary>
/// Inicjalizuje obiekt RBMember. Od tej chwili state == Initalized i isNull() == false
/// </summary>
void RBMember::build()
{
	state = Initialized;
	leftNode = new RBMember();
	rightNode = new RBMember();
	parentNode = new RBMember();
}
