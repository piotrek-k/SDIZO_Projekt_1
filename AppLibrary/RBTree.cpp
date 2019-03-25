#include "stdafx.h"
#include "RBTree.h"


RBMember* RBTree::treeInsert(int value)
{
	RBMember* newElem = new RBMember();
	newElem->build();
	newElem->value = value;

	RBMember* y = new RBMember(); //NULL
	RBMember* x = root;
	while (x->isNotNull()) {
		y = x;
		if (newElem->value < x->value) {
			x = x->leftNode;
		}
		else {
			x = x->rightNode;
		}
	}
	newElem->parentNode = y;
	if (y->isNull()) {
		root = newElem;
	}
	else if (newElem->value < y->value) {
		y->leftNode = newElem;
	}
	else {
		y->rightNode = newElem;
	}

	count++;

	return newElem;
}

void RBTree::leftRotate(RBMember * node)
{
	RBMember* y = node->rightNode;
	node->rightNode = y->leftNode;

	if (y->leftNode != NULL) {
		y->leftNode->parentNode = node;
	}
	y->parentNode = node->parentNode;
	if (node->parentNode == NULL) {
		root = y;
	}
	else if (node == node->parentNode->leftNode) {
		node->parentNode->leftNode = y;
	}
	else {
		node->parentNode->rightNode = y;
	}

	y->leftNode = node;
	node->parentNode = y;
}

void RBTree::rightRotate(RBMember * y)
{
	//zgodnie z rysunkiem, Cormen strona 306

	RBMember* x = y->leftNode;

	//alpha
	//zostaje

	//beta
	y->leftNode = x->rightNode;
	x->rightNode->parentNode = y;

	//gamma
	//zostaje

	if (y->parentNode->isNotNull()) {
		x->parentNode = y->parentNode;
	}
	else {
		x->parentNode = new RBMember();
		root = x;
	}

	if (y->parentNode->rightNode == y) {
		y->parentNode->rightNode = x;
	}
	else {
		y->parentNode->leftNode = x;
	}
	x->rightNode = y;

}

RBMember* RBTree::treeMinimum(RBMember * node)
{
	while (node->leftNode->isNotNull()) {
		node = node->leftNode;
	}
	return node;
}

RBMember * RBTree::treeSuccessor(RBMember * node)
{
	// je�li w�ze� ma prawego potomka, znajd� najmniejsz� warto�� zaczynaj�c od niego
	if (node->rightNode->isNotNull()) {
		return treeMinimum(node->rightNode);
	}
	// znajd� pierwszy przypadek rodzica, kt�ry jest lewym potomkiem
	// dojdziemy wtedy do pierwszego wi�kszego w�z�a
	RBMember* y = node->parentNode;
	while (y->isNotNull() && node == y->rightNode) {
		node = y;
		y = y->parentNode;
	}
	return y;
}

RBTree::RBTree()
{
}


RBTree::~RBTree()
{
}

void RBTree::rbInsert(int value)
{
	RBMember* x = treeInsert(value);
	x->color = Red;
	RBMember* y = new RBMember();

	// dodali�my w�ze� w kolorze czerwonym. trzeba upewni� si�, �e jego rodzic nie jest tego samego koloru
	while (x != root && x->parentNode->color == Red) {
		if (x->parentNode->parentNode != nullptr && x->parentNode->parentNode->isNotNull()) {
			if (x->parentNode == x->parentNode->parentNode->leftNode) {
				// rodzic nowego w�z�a jest lewym w�z�em

				y = x->parentNode->parentNode->rightNode; //pobierz prawy odpowiednik rodzica
				if (y->color == Red) {
					//prawy odpowiednik rodzica te� jest czerwony

					x->parentNode->color = Black; // zmie� rodzica na czarnego
					y->color = Black; // zmie� prawy odpowiednik rodzica na czarny
					x->parentNode->parentNode->color = Red;
					x = x->parentNode->parentNode;
				}
				else if (x == x->parentNode->rightNode) {
					//rodzic i jego odpow. maj� inne kolory
					//x jest prawym w�z�em

					//przyp 2
					x = x->parentNode;
					leftRotate(x);

					//rodzic i jego odpow. maj� inne kolory
					//x jest lewym w�z�em

					//przyp 3
					if (x != root) {
						x->parentNode->color = Black;
					}
					if (x->parentNode->parentNode != nullptr && x->parentNode->parentNode->isNotNull()) {
						x->parentNode->parentNode->color = Red;
						rightRotate(x->parentNode->parentNode);
					}
				}

			}
			else {
				// rodzic nowego w�z�a jest prawym w�z�em

				y = x->parentNode->parentNode->leftNode; //pobierz lewy odpowiednik rodzica
				if (y->color == Red) {
					//lewy odpowiednik rodzica te� jest czerwony

					x->parentNode->color = Black; // zmie� rodzica na czarnego
					y->color = Black; // zmie� lewy odpowiednik rodzica na czarny
					x->parentNode->parentNode->color = Red;
					x = x->parentNode->parentNode;
				}
				else if (x == x->parentNode->leftNode) {
					//rodzic i jego odpow. maj� inne kolory
					//x jest lewym w�z�em

					//przyp 2
					x = x->parentNode;
					rightRotate(x);

					//rodzic i jego odpow. maj� inne kolory
					//x jest prawym w�z�em

					//przyp 3
					if (x != root) {
						x->parentNode->color = Black;
					}
					if (x->parentNode->parentNode != nullptr && x->parentNode->parentNode->isNotNull()) {
						x->parentNode->parentNode->color = Red;
						leftRotate(x->parentNode->parentNode);
					}
				}
				
			}
		}
	}
	root->color = Black;
}

RBMember* RBTree::removeElement(RBMember* z)
{
	// algorytm zamiast fizycznie usuwa� w�ze�
	// usuwa jego potomka, i przypisuje sobie jego cechy

	RBMember* x;
	RBMember* y;
	if (z->leftNode->isNull() || z->rightNode->isNull()) {
		y = z;
	}
	else {
		y = treeSuccessor(z);
	}

	if (y->leftNode->isNotNull()) {
		x = y->leftNode;
	}
	else {
		x = y->rightNode;
	}
	x->parentNode = y->parentNode;

	if (y->parentNode->isNull()) {
		root = x;
	}
	else if (y == y->parentNode->leftNode) {
		y->parentNode->leftNode = x;
	}
	else {
		y->parentNode->rightNode = x;
	}

	if (y != z) {
		z->value = y->value;
	}

	if (y->color == Black) {
		// je�li y jest czarny, mamy dwa kolory czerwone pod rz�d
		RBDeleteFixup(x);
	}

	return y;
}

void RBTree::RBDeleteFixup(RBMember * x)
{
	// przywr�cenie w�asno�ci drzewa po usuni�ciu elementu

	RBMember* w;
	while (x != root && x->color == Black) {
		if (x == x->parentNode->leftNode) {
			w = x->parentNode->rightNode;

			if (w->color == Red) {
				w->color = Black;
				x->parentNode->color = Red;
				leftRotate(x->parentNode);
				w = x->parentNode->rightNode;
			}

			if (w->leftNode->color == Black && w->rightNode->color == Black) {
				w->color = Red;
				x = x->parentNode;
			}
			else if (w->rightNode->color == Black) {
				w->leftNode->color = Black;
				w->color = Red;
				rightRotate(w);
				w = x->parentNode->rightNode;
			}

			w->color = x->parentNode->color;
			x->parentNode->color = Black;
			w->rightNode->color = Black;
			leftRotate(x->parentNode);
			x = root;
		}
		else {
			w = x->parentNode->leftNode;

			if (w->color == Red) {
				w->color = Black;
				x->parentNode->color = Red;
				rightRotate(x->parentNode);
				w = x->parentNode->leftNode;
			}

			if (w->rightNode->color == Black && w->leftNode->color == Black) {
				w->color = Red;
				x = x->parentNode;
			}
			else if (w->leftNode->color == Black) {
				w->rightNode->color = Black;
				w->color = Red;
				leftRotate(w);
				w = x->parentNode->leftNode;
			}

			w->color = x->parentNode->color;
			x->parentNode->color = Black;
			w->leftNode->color = Black;
			rightRotate(x->parentNode);
			x = root;
		}

	}
}