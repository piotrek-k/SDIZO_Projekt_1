#include "pch.h"
#include "../AppLibrary/Heap.h"

//class HeapTest : public::testing::Test {
//protected:
//	Heap heap;
//
//	HeapTest() {
//		int initialArray[] = { 5, -2, 5, -4, 6, 12, 0 };
//		heap = Heap();
//		heap.populateFromArray(initialArray, 7);
//	}
//};

TEST(HeapTest_Standalone, LoadingFromFileWorksProperly) {
	// data ordered by adding

	Heap heap = Heap();
	heap.loadFromFile("../Tests/ExampleFilesWithData/ValuesForHeap.txt");
	int expectedResult[] = { 12, 5, 6, -4, -2, 5, 0 }; //how built heap should look like
	//int expectedResult[] = { 5, -2, 5, -4, 6, 12, 0 }; //heap without building

	ASSERT_EQ(heap.getDeclaredSize(), 7);

	int* heapAsArray = heap.toArray();
	EXPECT_EQ("12 5 6 -4 -2 5 0 ", heap.convertToString());
	for (int i = 0; i < heap.getDeclaredSize(); i++) {
		EXPECT_EQ(heapAsArray[i], expectedResult[i]);
	}
}

TEST(HeapTest_Standalone, ParentAndChildren) {
	// data ordered by buildHeap

	int initialArray[] = { 5, -2, 5, -4, 6, 12, 0 };
	Heap heap = Heap();
	heap.populateFromArray(initialArray, 7);
	heap.buildHeap();
	int* asArray = heap.toArray();

	EXPECT_EQ(asArray[heap.getIndexOfParent(4)], 6);
	EXPECT_EQ(asArray[heap.getIndexOfParent(2)], 12);
	EXPECT_EQ(asArray[heap.getRightChildIndex(1)], -2);
	EXPECT_EQ(asArray[heap.getLeftChildIndex(2)], 5);
}

TEST(HeapTest_Standalone, AddingTestWorksProperly) {
	// data ordered by adding

	Heap heap = Heap();
	heap.addElement(5);
	ASSERT_EQ(heap.getDeclaredSize(), 1);
	heap.addElement(10);
	ASSERT_EQ(heap.getDeclaredSize(), 2);
	int maxValue = heap.toArray()[0];
	EXPECT_EQ(maxValue, 10);
}

TEST(HeapTest_Standalone, BuildHeapShouldCreateCorrectOrder) {
	// data ordered by buildHeap

	Heap heap = Heap();
	int initialArray[] = { 5, -2, 5, -4, 6, 12, 0 };
	heap.populateFromArray(initialArray, 7);
	int expectedResult[] = { 12, 6, 5, -4, -2, 5, 0 };

	heap.buildHeap();

	//compareWithCurrentHeapState(heap, expectedResult);
	int* heapAsArray = heap.toArray();
	for (int i = 0; i < heap.getDeclaredSize(); i++) {
		EXPECT_EQ(heapAsArray[i], expectedResult[i]);
	}
}