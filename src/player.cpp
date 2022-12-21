#include "player.h"

Player::Player() {
    pos = sws::DM::vtov2("PLAYER:POS");
    r = FixRotation(sws::DM::vtof("PLAYER:ANGLE") * DEG2RAD);
    d_pos = new sws::vec2(cos(r), sin(r));
    w = sws::DM::vtof("PLAYER:WIDTH");
    wKey = false, aKey = false, sKey = false, dKey = false;
}

void Player::Draw(SDL_Window* win, SDL_Surface* sfc) {
    glColor3f(1.0, 0.0, 1.0);
    DrawPoint(w, pos->x, pos->y);
}

void Player::Update(Map* map) {
    Move(map);
}

void Player::Input(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
       switch(e.key.keysym.sym) {
            case SDLK_a:
                aKey = true;
                break;
            case SDLK_d:
                dKey = true;
                break;
            case SDLK_w:
                wKey = true;
                break;
            case SDLK_s:
                sKey = true;
                break;
       }
    }
    if (e.type == SDL_KEYUP) {
       switch(e.key.keysym.sym) {
            case SDLK_a:
                aKey = false;
                break;
            case SDLK_d:
                dKey = false;
                break;
            case SDLK_w:
                wKey = false;
                break;
            case SDLK_s:
                sKey = false;
                break;
       }
    }
}

void Player::Move(Map* map) {
    if (dKey) {
        r = FixRotation(r += DEG2RAD);
        d_pos->x = cos(r);
        d_pos->y = sin(r);
    }

    if (aKey) {
        r = FixRotation(r -= DEG2RAD);
        d_pos->x = cos(r);
        d_pos->y = sin(r);
    }
    CheckWallCollision(map);
}

void Player::CheckWallCollision(Map* map) {
    int xOffset = d_pos->x < 0 ? -8 : 8;
    int yOffset = d_pos->y < 0 ? -8 : 8;
    int xRelative = pos->x / 64;
    int yRelative = pos->y / 64;
    int addXOffset = (pos->x + xOffset) / 64;
    int subXOffset = (pos->x - xOffset) / 64;
    int addYOffset = (pos->y + yOffset) / 64;
    int subYOffset = (pos->y - yOffset) / 64;

    if (wKey) {
        if (map->GetWalls()[yRelative*map->GetX() + addXOffset] == 0)
            pos->x += d_pos->x;
        if (map->GetWalls()[addYOffset*map->GetX() + xRelative] == 0) 
            pos->y += d_pos->y;
    }

    if (sKey) {
        if (map->GetWalls()[yRelative*map->GetX() + subXOffset] == 0)
            pos->x -= d_pos->x;
        if (map->GetWalls()[subYOffset*map->GetX() + xRelative] == 0) 
            pos->y -= d_pos->y;
    }
}
