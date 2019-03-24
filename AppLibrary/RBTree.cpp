#include "stdafx.h"
#include "RBTree.h"


RBMember* RBTree::treeInsert(int value)
{
	RBMember* newElem = (RBMember*)malloc(sizeof(struct RBMember));
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
	RBMember* y = NULL;

	// dodaliœmy wêze³ w kolorze czerwonym. trzeba upewniæ siê, ¿e jego rodzic nie jest tego samego koloru
	while (x != root && x->parentNode->color == Red) {
		if (x->parentNode == x->parentNode->parentNode->leftNode) {
			// rodzic nowego wêz³a jest lewym wêz³em

			y = x->parentNode->parentNode->rightNode; //pobierz prawy odpowiednik rodzica
			if (y->color == Red) {
				//prawy odpowiednik rodzica te¿ jest czerwony

				x->parentNode->color = Black; // zmieñ rodzica na czarnego
				y->color = Black; // zmieñ prawy odpowiednik rodzica na czarny
				x->parentNode->parentNode->color = Red;
				x = x->parentNode->parentNode;
			}
			else if (x == x->parentNode->rightNode) {
				//rodzic i jego odpow. maj¹ inne kolory
				//x jest prawym wêz³em

				//przyp 2
				x = x->parentNode;
				//Left rotate (T, x)
			}
			//rodzic i jego odpow. maj¹ inne kolory
			//x jest lewym wêz³em

			//przyp 3
			x->parentNode->color = Black;
			x->parentNode->parentNode->color = Red;
			//Right rotate (T, x.parent.parent)
		}
		else {
			// rodzic nowego wêz³a jest prawym wêz³em

			y = x->parentNode->parentNode->leftNode; //pobierz lewy odpowiednik rodzica
			if (y->color == Red) {
				//lewy odpowiednik rodzica te¿ jest czerwony

				x->parentNode->color = Black; // zmieñ rodzica na czarnego
				y->color = Black; // zmieñ lewy odpowiednik rodzica na czarny
				x->parentNode->parentNode->color = Red;
				x = x->parentNode->parentNode;
			}
			else if (x == x->parentNode->leftNode) {
				//rodzic i jego odpow. maj¹ inne kolory
				//x jest lewym wêz³em

				//przyp 2
				x = x->parentNode;
				//Right rotate?
			}
			//rodzic i jego odpow. maj¹ inne kolory
			//x jest prawym wêz³em

			//przyp 3
			x->parentNode->color = Black;
			x->parentNode->parentNode->color = Red;
			//Left rotate ?
		}
		root->color = Black;
	}
}
