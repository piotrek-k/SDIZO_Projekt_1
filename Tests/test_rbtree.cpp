#include "pch.h"
#include "../AppLibrary/RBTree.h"

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


TEST(RBTreeTest, LeftRotate) {
	// data ordered by buildHeap
	RBTree rb = RBTree();
	/*rb.rbInsert

	EXPECT_EQ(asArray[heap.getIndexOfParent(4)], 6);
	EXPECT_EQ(asArray[heap.getIndexOfParent(2)], 12);
	EXPECT_EQ(asArray[heap.getRightChildIndex(1)], -2);
	EXPECT_EQ(asArray[heap.getLeftChildIndex(2)], 5);*/
}
