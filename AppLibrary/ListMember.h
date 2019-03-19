#pragma once

struct ListMember {
	int value = 0;
	int key = 0;
	ListMember* nextValue = nullptr;
	ListMember* prevValue = nullptr;
};