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
	RBTree();
	~RBTree();
	void loadFromFile(std::string FileName);
	void findValue(int value);
	void rbInsert(int value);
	void removeElement(int value);
	void display(std::ostream & stream);
};

