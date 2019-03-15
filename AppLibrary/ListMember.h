#pragma once

struct ListMember {
	int value;
	int key;
	ListMember* nextValue;
	ListMember* prevValue;
};