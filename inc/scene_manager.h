#pragma once

#include <vector>
#include <SDL3/SDL.h>
#include <memory>
#include "scene.h"
#include "input_handler.h"

class SceneManager{
private:
    std::vector<std::unique_ptr<Scene>>scenes = {};
    Scene* active_scene;
public:
    void add_scene(std::unique_ptr<Scene> scene);
    void scene_update(InputHandler& input_handler);
    void render_scene(SDL_Renderer& renderer);
};