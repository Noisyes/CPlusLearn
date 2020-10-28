#include "Wall.h"
#include<iostream>
using std::queue;
Wall* Wall::single = nullptr;
Wall::Wall()
{
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			if (i == 0 || j == 0||i==Column-1||j==Row-1)
			{
				map[i][j] = '*';
			}
			else
			{
				map[i][j] = ' ';
			}
		}
	}
	food firstFood = food();
	foodQueue.push(firstFood);
}

void Wall::ShowWall()
{
	food curfood = foodQueue.front();
	SetPos(curfood.pos.first, curfood.pos.second, 'O');
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			std::cout << map[i][j];
		}
		if (i == 8) std::cout <<  " author: noisyes";
		if (i == 9) std::cout <<  " up : w";
		if (i == 10) std::cout << " down : s";
		if (i == 11) std::cout << " left : a";
		if (i == 12) std::cout << " right : d";
		std::cout << std::endl;
	}
}

void Wall::SetPos(int x, int y, char c)
{
	if (x >= Column || y >= Row) return;
	map[x][y] = c;
}

char Wall::GetPos(int x, int y)
{
	if (x >= Column || y >= Row) return '!';
	return map[x][y];
}

Wall*  Wall::GetSingle()
{
	if (single == nullptr)
	{
		single = new Wall();
		return single;
	}
	return single;
}
