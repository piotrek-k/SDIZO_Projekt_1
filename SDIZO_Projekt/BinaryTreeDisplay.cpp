#include "pch.h"
#include "BinaryTreeDisplay.h"
#include "../AppLibrary/RBTree.h"
#include "../AppLibrary/Heap.h"


// Kod rysuj¹cy autorstwa user1571409
// https://stackoverflow.com/a/13755911/1804027

BinaryTreeDisplay::BinaryTreeDisplay()
{
}


BinaryTreeDisplay::~BinaryTreeDisplay()
{
}

int BinaryTreeDisplay::_print_t(RBMember *tree, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!tree) return 0;

	sprintf_s(b, "(%03d)", tree->value);

	int left = _print_t(tree->leftNode, 1, offset, depth + 1, s);
	int right = _print_t(tree->rightNode, 0, offset + left + width, depth + 1, s);

	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}

	return left + width + right;
}

void BinaryTreeDisplay::print_t(RBMember *tree)
{
	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf_s(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}

int BinaryTreeDisplay::_print_t(Heap *tree, int index, int is_left, int offset, int depth, char s[20][255])
{
	char b[20];
	int width = 5;

	if (!tree || !tree->indexIsValid(index)) return 0;

	sprintf_s(b, "(%03d)", tree->getValueAtIndex(index));

	int left = _print_t(tree, tree->getLeftChildIndex(index), 1, offset, depth + 1, s);
	int right = _print_t(tree, tree->getRightChildIndex(index), 0, offset + left + width, depth + 1, s);

	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];

	if (depth && is_left) {

		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

	}
	else if (depth && !is_left) {

		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width / 2 + i] = '-';

		s[2 * depth - 1][offset + left + width / 2] = '+';
		s[2 * depth - 1][offset - width / 2 - 1] = '+';
	}

	return left + width + right;
}

void BinaryTreeDisplay::print_t(Heap *tree)
{
	char s[20][255];
	for (int i = 0; i < 20; i++)
		sprintf_s(s[i], "%80s", " ");

	_print_t(tree, 0, 0, 0, 0, s);

	for (int i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}