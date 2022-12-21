#include "scene.h"

std::deque<std::unique_ptr<Scene>> SceneMgmt::scenes;

void SceneMgmt::Push(std::unique_ptr<Scene> s) {
    scenes.push_back(std::move(s));
}

void SceneMgmt::PopFront() {
    scenes.pop_front();
}

void SceneMgmt::PopBack() {
    scenes.pop_back();
}

void SceneMgmt::Draw(SDL_Window* win, SDL_Surface* sfc) {
    for (auto& s : scenes) s->Draw(win, sfc);
}

void SceneMgmt::Update() {
    scenes.back()->Update();
}

void SceneMgmt::Input(SDL_Event e) {
    scenes.back()->Input(e);
}
