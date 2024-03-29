#include "pch.h"
#include "../AppLibrary/List.h"

//// Utworzenie instancji klasy Table dla ka�dego z test�w
//class ListTest : public ::testing::Test {
//protected:
//	List list;
//
//	// You can remove any or all of the following functions if its body
//	// is empty.
//
//	ListTest() {
//		// You can do set-up work for each test here.
//		int initialArray[] = { 0, -2, 5, 99, 124, 1, 2 };
//		table = Table(7, initialArray);
//	}
//};

TEST(ListTest_Standalone, LoadingFromFileWorksProperly) {
	List list = List();
	list.loadFromFile("../Tests/ExampleFilesWithData/ValuesForTable.txt");
	//int endArray[] = { 0, -2, 5, 99, 124, 1, 2 };
	int endArray[] = { 2, 1, 124, 99, 5, -2, 0 };
	//int endKeyValues[] = { 0, 1, 2, 3, 4, 5, 6 };
	int* generatedArr = list.toArray();

	ASSERT_EQ(list.getDeclaredSize(), 7);

	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}

	/*ListMember* lm = list.getFirstValue();
	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(lm->key, endKeyValues[i]);
		lm = lm->prevValue;
	}*/
}
TEST(ListTest_Standalone, AddedValuesToList) {
	int endArray[] = { -22, 10, 5 };
	List list = List();
	list.addElementAsFirst(5);
	list.addElementAsFirst(10);
	list.addElementAsFirst(-22);
	int* generatedArr = list.toArray();

	EXPECT_EQ(list.getDeclaredSize(), 3);
	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}
}

TEST(ListTest_Standalone, AddedValuesAtIndex) {
	int endArray[] = { -22, 55, 10, 5 }; //od konca
	List list = List();
	list.addElementAsFirst(5);
	list.addElementAsFirst(10);
	list.addElementAsFirst(-22);
	list.addElementAtIndex(1, 55);
	int* generatedArr = list.toArray();

	EXPECT_EQ(list.getDeclaredSize(), 4);
	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}
}

TEST(ListTest_Standalone, RemoveValueAndConsistencyCheck) {
	//int endArray[] = { 88, 234, -22 };
	int endArray[] = { -22, 234, 88 };
	List list = List();
	list.addElementAsFirst(5);
	list.addElementAsFirst(10);
	list.addElementAsFirst(88);
	list.addElementAsFirst(234);
	list.addElementAsFirst(-22);
	list.removeElementByValue(10);
	list.removeElementByValue(10);
	list.removeElementByValue(10);
	list.removeElementByValue(10);
	list.removeElementByValue(5);
	int* generatedArr = list.toArray();

	EXPECT_EQ(list.getDeclaredSize(), 3);
	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}

	// CONSISTENCY CHECK
	ListMember* lm = list.getFirstValue();
	ListMember* beginning = lm;
	for (int a = list.getDeclaredSize()-1; a > 0; a--) {
		if (lm->prevValue)
			lm = lm->prevValue;
	}
	for (int a = 0; a < list.getDeclaredSize()-1; a++) {
		lm = lm->nextValue;
	}
	EXPECT_EQ(lm, beginning);
}

TEST(ListTest_Standalone, RandomListConsistencyCheck) {
	List list = List();
	list.generateRandom(6, 10);
	int* generatedArr = list.toArray();

	EXPECT_EQ(list.getDeclaredSize(), 6);

	// CONSISTENCY CHECK
	ListMember* lm = list.getFirstValue();
	ListMember* beginning = lm;
	for (int a = list.getDeclaredSize() - 1; a > 0; a--) {
		if (lm->prevValue)
			lm = lm->prevValue;
	}
	for (int a = 0; a < list.getDeclaredSize() - 1; a++) {
		lm = lm->nextValue;
	}
	EXPECT_EQ(lm, beginning);
}