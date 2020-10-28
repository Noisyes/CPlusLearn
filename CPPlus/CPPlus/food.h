#pragma once
#include <utility>
#include <random>
struct food
{
	int value;
	std::pair<int, int> pos;
	food();
	food(const food& cur);
};