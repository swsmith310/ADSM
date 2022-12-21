#include "play.h"

Play::Play() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   p = new Player();
   map = new Map(64);
}

void Play::Draw(SDL_Window* win, SDL_Surface* sfc) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    map->Draw(p);
    p->Draw(win, sfc);
    SDL_GL_SwapWindow(win);
}

void Play::Update() {
    p->Update(map);
}

void Play::Input(SDL_Event e) {
    if (e.type == SDL_KEYDOWN) {
        switch(e.key.keysym.sym) {
            case SDLK_ESCAPE:
                SceneMgmt::Push(std::make_unique<Pause>());
                break;
        }
    }
    p->Input(e);
}
