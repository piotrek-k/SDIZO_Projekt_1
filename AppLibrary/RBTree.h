#pragma once
#include "RBMember.h"
#include <string>
class RBTree
{
	int count = 0;
public:
	RBMember* root = (RBMember*)malloc(sizeof(struct RBMember));
	RBMember* treeInsert(int value);
	void leftRotate(RBMember* node);
	void rightRotate(RBMember* node);
	RBMember* treeMinimum(RBMember* node);
	RBMember* treeSuccessor(RBMember* node);
	RBTree();
	~RBTree();
	void loadFromFile(std::string FileName);
	RBMember* findValue(int value);
	void rbInsert(int value);
	RBMember* removeElement(RBMember* value);
	void RBDeleteFixup(RBMember* x);
	void display(std::ostream & stream);
};

