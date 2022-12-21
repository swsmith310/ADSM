#ifndef MAP_H
#define MAP_H
#include <cmath>
#include <vector>
#include <swsdm.h>
#include "constants.h"
#include "gfx.h"
#include "player.h"

class Player;

class Map {
    int x, y;
    int size;
    std::vector<int8_t> walls;
    std::vector<int8_t> floor; 
    std::vector<int8_t> ceiling;
public:
    Map(int s);
    void Draw(Player* p);
    void DrawRays(Player* p);
    std::vector<int8_t> GetWalls() { return walls; }
    int GetX() { return x; }
    int GetY() { return y; }
};

#endif
