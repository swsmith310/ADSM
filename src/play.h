#ifndef PLAY_H
#define PLAY_H

#include "map.h"
#include "scene.h"
#include "player.h"
#include "pause.h"

class Play : public Scene {
    Player* p; 
    Map* map;
public:
    Play();
    void Draw(SDL_Window* win, SDL_Surface* sfc) override;
    void Update() override;
    void Input(SDL_Event e) override;
};

#endif
