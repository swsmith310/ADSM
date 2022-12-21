#ifndef PAUSE_H
#define PAUSE_H

#include "scene.h"

class Pause : public Scene {
public:
    Pause();
    void Draw(SDL_Window* win, SDL_Surface* sfc) override;
    void Update() override;
    void Input(SDL_Event e) override;
};

#endif
