#include "pch.h"
#include "../AppLibrary/Table.h"
//#include "gtest/gtest.h"

namespace {

	// Utworzenie instancji klasy Table dla ka¿dego z testów
	class TableTest : public ::testing::Test {
	protected:
		Table table;

		// You can remove any or all of the following functions if its body
		// is empty.

		TableTest() {
			// You can do set-up work for each test here.
			int initialArray[] = { 0, -2, 5, 99, 124, 1, 2 };
			table = Table(7, initialArray);
		}

		~TableTest() override {
			// You can do clean-up work that doesn't throw exceptions here.
		}

		// If the constructor and destructor are not enough for setting up
		// and cleaning up each test, you can define the following methods:

		void SetUp() override {
			// Code here will be called immediately after the constructor (right
			// before each test).
		}

		void TearDown() override {
			// Code here will be called immediately after each test (right
			// before the destructor).
		}

		// Objects declared here can be used by all tests in the test case for Foo.
	};

	TEST(TableTest_Standalone, LoadingFromFileWorksProperly) {
		Table table = Table();
		table.loadFromFile("../Tests/ExampleFilesWithData/ValuesForTable.txt");
		int iar2[] = { 0, -2, 5, 99, 124, 1, 2 };

		ASSERT_EQ(table.getDeclaredSize(), 7);

		for (int i = 0; i < table.getDeclaredSize(); i++) {
			EXPECT_EQ(table.getValueAtIndex(i), iar2[i]);
		}
	}

	TEST_F(TableTest, RemovedBeginningOfTable) {
		int endArray[] = { -2, 5, 99, 124, 1, 2 };

		table.removeElement(0);

		EXPECT_EQ(table.getDeclaredSize(), 6);
		for (int i = 0; i < table.getDeclaredSize(); i++) {
			EXPECT_EQ(table.getValueAtIndex(i), endArray[i]);
		}
	}

	TEST_F(TableTest, AddedBeginningOfTable) {
		int endArray[] = { 0, 222, -2, 5, 99, 124, 1, 2 };

		table.addElement(1, 222);

		EXPECT_EQ(table.getDeclaredSize(), 8);
		for (int i = 0; i < table.getDeclaredSize(); i++) {
			EXPECT_EQ(table.getValueAtIndex(i), endArray[i]);
		}
	}
}