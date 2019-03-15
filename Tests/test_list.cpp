#include "pch.h"
#include "../AppLibrary/List.h"

//// Utworzenie instancji klasy Table dla ka¿dego z testów
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
	int endArray[] = { 0, -2, 5, 99, 124, 1, 2 };
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
	int endArray[] = { 5, 10, -22 };
	List list = List();
	list.addElement(5);
	list.addElement(10);
	list.addElement(-22);
	int* generatedArr = list.toArray();

	EXPECT_EQ(list.getDeclaredSize(), 3);
	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}
}

TEST(ListTest_Standalone, AddedValuesAtIndex) {
	int endArray[] = { 5, 55, 10, -22 };
	List list = List();
	list.addElement(5);
	list.addElement(10);
	list.addElement(-22);
	list.addElementAtIndex(1, 55);
	int* generatedArr = list.toArray();

	EXPECT_EQ(list.getDeclaredSize(), 4);
	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}
}

TEST(ListTest_Standalone, RemoveValue) {
	int endArray[] = { 5, 88, 234, -22 };
	List list = List();
	list.addElement(5);
	list.addElement(10);
	list.addElement(88);
	list.addElement(234);
	list.addElement(-22);
	list.removeElementByValue(10);
	int* generatedArr = list.toArray();

	EXPECT_EQ(list.getDeclaredSize(), 4);
	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}
}