#include "player.h"

player* player::getPlayer()
{
    if (_player == nullptr)
    {
        _player = new player();
    }
    return _player;
}
player::player()
{
    curDir = 'd';
}
