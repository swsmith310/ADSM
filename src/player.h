#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <swsdm.h>
#include "constants.h"
#include "gfx.h"
#include "map.h"

class Map;

class Player {
    sws::vec2* pos;
    sws::vec2* d_pos;
    float r;
    float w;
    bool wKey, aKey, sKey, dKey;
public:
    Player();
    void Draw(SDL_Window* win, SDL_Surface* sfc) ;
    void Update(Map* map) ;
    void Input(SDL_Event e) ;
    void Move(Map* map);
    void CheckWallCollision(Map* map);
    float GetR() { return r; }
    sws::vec2* GetPos() { return pos; }
};
#endif /* ! */
