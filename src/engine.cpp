#include "engine.h"
#include "play.h"

void SetGLAttributes() {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
}

Engine::Engine() {
  sws::DM();
  win_size = sws::DM::vtov2("WIN:SIZE");
  SDL_Init(SDL_INIT_VIDEO);
  SetGLAttributes();
  IMG_Init(IMG_INIT_PNG);
  active = true;
  win = SDL_CreateWindow("ADSM", 0, 0, win_size->x, win_size->y, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN);
  ctx = SDL_GL_CreateContext(win);
  sfc = SDL_GetWindowSurface(win);
  gluOrtho2D(0, win_size->x, win_size->y, 0);
  SceneMgmt::Push(std::make_unique<Play>());
}

void Engine::Run() {
  while (active) {
    Input();
    Update();
    Draw();
  }
}

void Engine::Input() {
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) active = false;
    SceneMgmt::Input(e);
  }
}

void Engine::Update() {
    SceneMgmt::Update();
}

void Engine::Draw() {
    glEnable(GL_MULTISAMPLE);
    SceneMgmt::Draw(win, sfc);
}
