#include "pch.h"
#include "../AppLibrary/RBTree.h"

RBTree* buildTreeFromBook() {
	RBTree* rb = new RBTree();
	rb->treeInsert(7);
	rb->treeInsert(4);
	rb->treeInsert(11);
	rb->treeInsert(3);
	rb->treeInsert(6);
	rb->treeInsert(9);
	rb->treeInsert(18);
	rb->treeInsert(2);
	rb->treeInsert(14);
	rb->treeInsert(19);
	rb->treeInsert(12);
	rb->treeInsert(17);
	rb->treeInsert(22);
	rb->treeInsert(20);
	return rb;
}

TEST(RBTreeTest, BST_Insertion) {
	RBTree rb = RBTree();

	rb.treeInsert(5);
	RBMember* x = rb.root;
	ASSERT_EQ(x->value, 5);

	rb.treeInsert(20);
	x = x->rightNode;
	ASSERT_EQ(x->value, 20);

	rb.treeInsert(1);
	x = rb.root->leftNode;
	ASSERT_EQ(x->value, 1);

	rb.treeInsert(2);
	x = x->rightNode;
	ASSERT_EQ(x->value, 2);
}

TEST(RBTreeTest, BuildingSampleTree) {
	RBTree* rb = buildTreeFromBook();

	RBMember* x = rb->root;
	RBMember* y = rb->root;
	ASSERT_EQ(x->value, 7);
	x = x->rightNode;
	ASSERT_EQ(x->value, 11);
	x = x->rightNode;
	ASSERT_EQ(x->value, 18);
	y = x->leftNode;
	x = x->rightNode;
	ASSERT_EQ(x->value, 19);
	ASSERT_EQ(y->value, 14);
	y = y->leftNode;
	x = x->rightNode;	
	ASSERT_EQ(x->value, 22);
	ASSERT_EQ(y->value, 12);
}

TEST(RBTreeTest, LeftRotate) {
	RBTree* rb = buildTreeFromBook();
	
	RBMember* movePoint = rb->root->rightNode;
	rb->leftRotate(movePoint);

	RBMember* x = rb->root;
	ASSERT_EQ(x->value, 7);
	x = x->rightNode;
	ASSERT_EQ(x->value, 18);
	x = x->rightNode;
	ASSERT_EQ(x->value, 19);
	x = x->rightNode;
	ASSERT_EQ(x->value, 22);
	x = x->leftNode;
	ASSERT_EQ(x->value, 20);
}

TEST(RBTreeTest, RightRotate) {
	RBTree* rb = buildTreeFromBook();

	RBMember* movePoint = rb->root->rightNode->rightNode;
	rb->rightRotate(movePoint);

	RBMember* x = rb->root;
	ASSERT_EQ(x->value, 7);
	x = x->rightNode;
	ASSERT_EQ(x->value, 11);
	x = x->rightNode;
	ASSERT_EQ(x->value, 14);
	x = x->leftNode;
	ASSERT_EQ(x->value, 12);

	x = rb->root;
	ASSERT_EQ(x->value, 7);
	x = x->rightNode;
	ASSERT_EQ(x->value, 11);
	x = x->rightNode;
	ASSERT_EQ(x->value, 14);
	x = x->rightNode;
	ASSERT_EQ(x->value, 18);
	x = x->leftNode;
	ASSERT_EQ(x->value, 17);
}