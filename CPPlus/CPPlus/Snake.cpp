#include"Snake.h"
#include "Wall.h"
#include<iostream>
using std::list;
Snake::Snake(pair<int, int> head)
{
	headPos = head;
	body.push_back(headPos);
}

void Snake::SetSnake()
{
	Wall* wall = Wall::GetSingle();
	if (wall == nullptr)
	{
		std::cout << "»¹Ã»Ç½ÄØ" << std::endl;
		return;
	}
	wall->SetPos(headPos.first, headPos.second,'@');
}

void Snake::ShowSnake()
{
	Wall* wall = Wall::GetSingle();
	for (list<pair<int, int>>::iterator it = body.begin(); it != body.end(); it++)
	{
		if (it == body.begin())
			wall->SetPos((*it).first, (*it).second, '@');
		else
			wall->SetPos((*it).first, (*it).second, '=');
	}
}

void Snake::UpdateSnake()
{
	Wall* wall = Wall::GetSingle();
	
}

Snake* Snake::GetSingle()
{
	if (single == nullptr)
	{
		single = new Snake();
	}
	return single;
}
Snake* Snake::single = nullptr;
