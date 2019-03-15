#include "pch.h"
#include "../AppLibrary/Table.h"
//#include "gtest/gtest.h"

namespace {

	// Utworzenie instancji klasy Table dla ka¿dego z testów
	//class TableTest : public ::testing::Test {
	//protected:
	//	Table table;

	//	// You can remove any or all of the following functions if its body
	//	// is empty.

	//	TableTest() {
	//		// You can do set-up work for each test here.
	//		table = Table();
	//	}

	//	~TableTest() override {
	//		// You can do clean-up work that doesn't throw exceptions here.
	//	}

	//	// If the constructor and destructor are not enough for setting up
	//	// and cleaning up each test, you can define the following methods:

	//	void SetUp() override {
	//		// Code here will be called immediately after the constructor (right
	//		// before each test).
	//		table.loadFromFile("../Tests/ExampleFilesWithData/ValuesForTable.txt");
	//	}

	//	void TearDown() override {
	//		// Code here will be called immediately after each test (right
	//		// before the destructor).
	//	}

	//	// Objects declared here can be used by all tests in the test case for Foo.
	//};

	TEST(TableTest, LoadingFromFileWorksProperly) {
		Table table = Table();
		table.loadFromFile("../Tests/ExampleFilesWithData/ValuesForTable.txt");
		int iar2[] = { 0, -2, 5, 99, 124, 1, 2 };

		ASSERT_EQ(table.getDeclaredSize(), 7);

		for (int i = 0; i < table.getDeclaredSize(); i++) {
			EXPECT_EQ(table.getValueAtIndex(i), iar2[i]);
		}
	}

	/*TEST_F(TableTest, RemovedBeginningOfTable) {

	}

	TEST_F(TableTest, AddedBeginningOfTable) {

	}

	TEST_F(TableTest, RemovedEndOfTable) {

	}

	TEST_F(TableTest, AddedEndOfTable) {

	}

	TEST_F(TableTest, RemovedRandomValueOfTable) {

	}

	TEST_F(TableTest, AddedRandomValueOfTable) {

	}*/
}