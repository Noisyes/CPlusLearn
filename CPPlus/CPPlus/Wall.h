#pragma once
#include <vector>
#include<string>
#include <queue>
#include "food.h"
class Wall
{
public:
	void ShowWall();
	void SetPos(int x, int y, char c);
	char GetPos(int x, int y);
	static Wall* GetSingle();
	enum widthAndHeight
	{
		Column = 20,
		Row = 70
	};
private :
	Wall();
	Wall(const Wall& wall);
	char map[Column][Row];
	static Wall* single;
	std::queue<food> foodQueue;

};