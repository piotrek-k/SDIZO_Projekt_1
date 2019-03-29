#include "pch.h"
#include "../AppLibrary/RBTree.h"

RBTree* buildBSTTreeFromBook() {
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

RBTree* buildRBTreeFromBook() {
	//Cormen 310
	RBTree* rb = new RBTree();
	rb->rbInsert(11);
	rb->rbInsert(2);
	rb->rbInsert(14);
	rb->rbInsert(1);
	rb->rbInsert(7);
	rb->rbInsert(15);
	rb->rbInsert(5);
	rb->rbInsert(8);
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
	RBTree* rb = buildBSTTreeFromBook();

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
	RBTree* rb = buildBSTTreeFromBook();
	
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
	RBTree* rb = buildBSTTreeFromBook();

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

TEST(RBTreeTest, RBInsert) {
	RBTree* rb = buildRBTreeFromBook();

	rb->rbInsert(4);

	ASSERT_EQ(rb->root->value, 7);
	ASSERT_EQ(rb->root->leftNode->value, 2);
	ASSERT_EQ(rb->root->rightNode->value, 11);
}

TEST(RBTreeTest, treeMinimum) {
	RBTree* rb = buildRBTreeFromBook();

	RBMember* m = rb->treeMinimum(rb->root);

	ASSERT_EQ(m->value, 1);
}

TEST(RBTreeTest, treeSuccessor) {
	RBTree* rb = buildRBTreeFromBook();

	RBMember* startPoint = rb->root->leftNode->rightNode->rightNode;
	RBMember* m = rb->treeSuccessor(startPoint);

	ASSERT_EQ(startPoint->value, 8);

	ASSERT_EQ(m->value, 11);
}

bool treeCorrect(RBMember* m) {
	if (m->leftNode->isNull() && m->rightNode->isNull()) {
		return true;
	}
	if (m->color == m->leftNode->color || m->color == m->rightNode->color) {
		return false;
	}
	return treeCorrect(m->leftNode) && treeCorrect(m->rightNode);
}

TEST(RBTreeTest, deleteElement) {
	RBTree* rb = buildRBTreeFromBook();

	//sprawdz czy usuwany element istnieje
	RBMember* objToDel1 = rb->findValue(11);
	RBMember* objToDel2 = rb->findValue(7);
	RBMember* objToDel3 = rb->findValue(5);
	ASSERT_TRUE(objToDel1 != NULL);
	ASSERT_TRUE(objToDel2 != NULL);
	ASSERT_TRUE(objToDel3 != NULL);
	//rb->removeElement(jakis_element);
	rb->removeElement(objToDel1);
	rb->removeElement(objToDel2);
	rb->removeElement(objToDel3);
	//sprobuj znowu znalezc ten element
	objToDel1 = rb->findValue(11);
	objToDel2 = rb->findValue(7);
	objToDel3 = rb->findValue(5);
	EXPECT_TRUE(objToDel1 == NULL);
	EXPECT_TRUE(objToDel2 == NULL);
	EXPECT_TRUE(objToDel3 == NULL);
	//sprawdz czy wlasnosci zachowane
	EXPECT_TRUE(treeCorrect(rb->root));
}

TEST(RBTreeTest, findValue) {
	RBTree* rb = buildRBTreeFromBook();

	EXPECT_TRUE(rb->findValue(11) != NULL);
	EXPECT_TRUE(rb->findValue(14) != NULL);
	EXPECT_TRUE(rb->findValue(7) != NULL);
	EXPECT_TRUE(rb->findValue(5) != NULL);

	EXPECT_TRUE(rb->findValue(9) == NULL);
}

TEST(RBTreeTest, generatingRandomWorksWell) {
	RBTree* rb = new RBTree();
	EXPECT_NO_THROW(rb->generateRandom(10, 10));
}

int counter(RBMember* mem) {
	if (mem->isNull()) {
		return 0;
	}
	if (mem->leftNode->isNull() && mem->rightNode->isNull()) {
		return 1;
	}
	return counter(mem->leftNode) + counter(mem->rightNode) + 1;
}

TEST(RBTreeTest, treesHaveProperSize) {
	RBTree* rb = buildRBTreeFromBook();

	EXPECT_EQ(counter(rb->root), 8);

	rb = new RBTree();
	rb->rbInsert(0);
	rb->rbInsert(1);
	rb->rbInsert(2);
	rb->rbInsert(3);
	rb->rbInsert(4);
	rb->rbInsert(5);
	rb->rbInsert(6);
	rb->rbInsert(7);
	rb->rbInsert(8);
	rb->rbInsert(9);
	EXPECT_EQ(counter(rb->root), 10);
}