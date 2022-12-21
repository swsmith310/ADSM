#include "pause.h"

Pause::Pause() {}

void Pause::Draw(SDL_Window* win, SDL_Surface* sfc) {}

void Pause::Update() {}

void Pause::Input(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
        switch(e.key.keysym.sym) {
            case SDLK_ESCAPE:
                SceneMgmt::PopBack();
                break;
        }
    }
}
