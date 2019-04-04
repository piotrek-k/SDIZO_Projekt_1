#pragma once
#include <iostream>
#include "../AppLibrary/RBTree.h"
#include "../AppLibrary/Heap.h"
using namespace std;

class BinaryTreeDisplay
{
public:
	BinaryTreeDisplay();
	~BinaryTreeDisplay();
	int _print_t(RBMember *tree, int is_left, int offset, int depth, char s[20][255]);
	void print_t(RBMember *tree);
	int _print_t(Heap *tree, int index, int is_left, int offset, int depth, char s[20][255]);
	void print_t(Heap *tree);
};

