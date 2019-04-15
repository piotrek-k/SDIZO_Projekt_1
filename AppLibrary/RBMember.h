#pragma once

enum RBMemberTreeColor
{
	Red,
	Black
};

enum RBMemberState
{
	NotInitialized,
	Initialized
};

class RBMember {
private:
	RBMemberState state = NotInitialized; // omini�cie problemu z lokowaniem pami�ci
public:
	int value = 0;
	RBMemberTreeColor color = Black;
	RBMember* leftNode;
	RBMember* rightNode;
	RBMember* parentNode;

	RBMember();

	bool isNotNull();
	bool isNull();
	void build();
};