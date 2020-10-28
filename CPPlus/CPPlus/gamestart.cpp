#include<iostream>
#include "Wall.h"
#include "Snake.h"
#include<utility>
using namespace std;
int main()
{
	Wall* wall;
	wall = Wall::GetSingle();
	Snake* snake = Snake::GetSingle();
	snake->SetSnake();
	wall->ShowWall();
	while (snake->isAlive())
	{

	}
	return 0;
}