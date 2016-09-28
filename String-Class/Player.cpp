#include "Player.h"
#include<iostream>
#include<Windows.h>
Player::Player(char * Name, bool Sword, bool Key, bool BossKey, int x, int y)
{
	m_Name = Name;
	m_hasSword = Sword;
	m_hasTreasure = Key;
	m_hasBossKey = BossKey;
	m_positionX = x;
	m_positionY = y;
}

int Player::moveWest()
{
	m_positionX--;
	return m_positionX;
}

int Player::moveEast()
{
	m_positionX++;
	return m_positionX;
}

int Player::moveSouth()
{
	m_positionY++;
	return m_positionY;
}

int Player::moveNorth()
{
	m_positionY--;
	return m_positionY;
}

char * Player::Response()
{
	char PlayerResponse[255];
	std::cin.getline(PlayerResponse, 255);
	system("cls");
	return PlayerResponse;
}

int Player::CheckResponse(MyString Answer, Room Rooms[][5])
{
	if (Answer.compare("help") == true)
	{
		CheckResponse(Response(), Rooms);
	}
	else if (Answer.findSubString("move") == true)
	{
		if (Answer.findSubString("east") == true)
		{
			if (Rooms[m_positionY][m_positionX].m_EastDoor == false)
			{
				std::cout << "Are you retarded? Try again." << std::endl;
				CheckResponse(Response(), Rooms);
			}
			else
			{
				moveEast();
			}
		}
		else if (Answer.findSubString("south") == true)
		{
			if (Rooms[m_positionY][m_positionX].m_SouthDoor == false)
			{
				std::cout << "Are you retarded? Try again." << std::endl;
				CheckResponse(Response(), Rooms);
			}
			else
			{
				moveSouth();
			}
		}
		else if (Answer.findSubString("west") == true && Rooms[m_positionY][m_positionX].m_WestDoor == true)
		{
			if (Rooms[m_positionY][m_positionX].m_WestDoor == false)
			{
				std::cout << "Are you retarded? Try again." << std::endl;
				CheckResponse(Response(), Rooms);
			}
			else
			{
				moveWest();
			}
		}
		else if (Answer.findSubString("north") == true && Rooms[m_positionY][m_positionX].m_NorthDoor == true)
		{
			if (Rooms[m_positionY][m_positionX].m_NorthDoor == false)
			{
				std::cout << "Are you retarded? Try again." << std::endl;
				CheckResponse(Response(), Rooms);
			}
			else
			{
				moveNorth();
			}
		}
	}
	else if (Answer.findSubString("grab") == true || Answer.findSubString("pickup") == true)
	{
		if (Answer.findSubString("key") && Rooms[m_positionY][m_positionX].m_HasTreasureKey == true)
		{
			std::cout << "You picked up the treasure key." << std::endl;

			m_hasTreasure = true;
		}
		else if (Answer.findSubString("sword") && Rooms[m_positionY][m_positionX].m_HasSword == true)
		{
			std::cout << "You picked up the shining shortsword." << std::endl;
			m_hasSword = true;
		}
		else if (Answer.findSubString("key") && Rooms[m_positionY][m_positionX].m_HasBossKey == true)
		{
			std::cout << "You picked up the key to the boss room." << std::endl;

			m_hasBossKey = true;
		}
	}
	else if (Answer.findSubString("fight") && Rooms[m_positionY][m_positionX].m_HasEnemy == true)
	{
		if (m_hasSword == false)
		{
			std::cout << "You charged forward and were decimated." << std::endl;
			Sleep(2000);
			return -1;
		}
		else
		{
			std::cout << "You stabbed the creature in the chest and killed it.\nWhat will you do?";
		}
	}
	else if (Answer.findSubString("press") && Rooms[m_positionY][m_positionX].m_HasDeathButton == true)
	{
		std::cout << "You pressed the button and spikes shot out from in front of you impaling you in 50 different places..." << std::endl;
		Sleep(2000);
		return -1;
	}
	else if ((Answer.findSubString("go down") || Answer.findSubString("jump down")) && Rooms[m_positionY][m_positionX].m_HasTrapHole == true)
	{
		std::cout << "You went down into the hole and landed on a bed of spikes..." << std::endl;
		Sleep(2000);
		return -1;
	}
	else if (Answer.findSubString("drink") || Answer.findSubString("eat"))
	{
		std::cout << "You drank the strange liquid and you were teleported to a random room." << std::endl;
		do
		{
			m_positionX = rand() % 5;
			m_positionY = rand() % 5;
		} while (Rooms[m_positionY][m_positionX].m_Empty == false);
	}
	else
	{
		std::cout << "Are you retarded? Try again." << std::endl;
		CheckResponse(Response(), Rooms);
	}
	return 0;
}
