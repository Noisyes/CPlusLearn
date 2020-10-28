#include "food.h"
food::food()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(2, 18);
	pos.first = dis(gen);
	pos.second = dis(gen);
	value = pos.first * pos.second;
}

food::food(const food& cur)
{
	this->value = cur.value;
	this->pos = cur.pos;
}
