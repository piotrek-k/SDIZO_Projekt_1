#include "pch.h"
#include "../AppLibrary/List.h"


TEST(ListTest_Standalone, LoadingFromFileWorksProperly) {
	List list = List();
	list.loadFromFile("../Tests/ExampleFilesWithData/ValuesForTable.txt");
	int endArray[] = { 0, -2, 5, 99, 124, 1, 2 };
	int* generatedArr = list.toArray();

	ASSERT_EQ(list.getDeclaredSize(), 7);

	for (int i = 0; i < list.getDeclaredSize(); i++) {
		EXPECT_EQ(generatedArr[i], endArray[i]);
	}
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