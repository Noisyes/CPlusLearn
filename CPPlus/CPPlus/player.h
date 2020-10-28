#pragma once
#include <windows.h>
class player
{
public:
	char curDir;
	player* getPlayer();
	void changeDir();
private:
	static player* _player;
	player();
};