#pragma once
#include<list>
#include<utility>
using std::list;
using std::pair;
class Snake
{
private:
	Snake(pair<int, int> head = {5,5});
	Snake(const Snake &snake);
	list<pair<int, int>> body;
	pair<int, int> headPos;
	static Snake* single;

public:
	static Snake* GetSingle();
	void SetSnake();
	void ShowSnake();
	void UpdateSnake();
	bool isAlive()
	{
		pair<int, int> head = body.front();
		if (head.first <= 0 || head.first >= Wall::Row || head.second <= 0 || head.second >= Wall::Column) return false;
		return true;
	}
};

