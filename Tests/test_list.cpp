#include "pch.h"
#include "../AppLibrary/List.h"

TEST(ListTest_Standalone, AddedValuesToList) {
	int endArray[] = { -22, 10, 5 };
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