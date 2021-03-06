#pragma once
#include "Rooms.h"
#include "MyString.h"
class Player
{
public:
	Player() {};
	Player(bool,bool,bool,int,int);
	int CheckResponse(MyString,Room [][5]);
	char * Response();
	int moveNorth();
	int m_positionX;
	int m_positionY;
	int moveSouth();
	int moveEast();
	int moveWest();
	bool m_hasSword;
	bool m_hasTreasure;
	bool m_hasBossKey;
	void setPrevious(int,int);
private:
	int m_PreviousX;
	int m_PreviousY;
};