#pragma once
#include "RBMember.h"
#include <string>
class RBTree
{
	int count = 0;
public:
	RBTree();
	~RBTree();
	RBMember* root = new RBMember();
	RBMember* treeInsert(int value);
	void leftRotate(RBMember* node);
	void rightRotate(RBMember* node);
	RBMember* treeMinimum(RBMember* node);
	RBMember* treeSuccessor(RBMember* node);
	void loadFromFile(std::string FileName);
	void generateRandom(int size, int range);
	RBMember* findValue(int value);
	void rbInsert(int value);
	void removeElement(int value);
	RBMember* removeElement(RBMember* value);
	void RBDeleteFixup(RBMember* x);
	void display(std::ostream & stream);
};

