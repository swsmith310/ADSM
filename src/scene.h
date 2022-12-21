#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <GL/glu.h>
#include <memory>
#include <deque>

struct Scene {
    Scene() = default;
    virtual ~Scene() = default;
    virtual void Draw(SDL_Window* win, SDL_Surface* sfc) = 0; 
    virtual void Update() = 0; 
    virtual void Input(SDL_Event e) = 0;
};

class SceneMgmt {
    static std::deque<std::unique_ptr<Scene>> scenes;   
public:
    SceneMgmt() = default;
    static void Push(std::unique_ptr<Scene> s);
    static void PopFront();
    static void PopBack();
    static void Draw(SDL_Window* win, SDL_Surface* sfc);
    static void Update();
    static void Input(SDL_Event e);
};

#endif
