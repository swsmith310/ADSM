#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <GL/glu.h>
#include <swsdm.h>
#include "scene.h"

class Engine {
  sws::vec2* win_size;
  bool active;
  SDL_Window* win;
  SDL_GLContext ctx;
  SDL_Surface* sfc;
  SDL_Event e;
public:
  Engine();
  void Run();
  void Draw();
  void Update();
  void Input();
};

#endif
