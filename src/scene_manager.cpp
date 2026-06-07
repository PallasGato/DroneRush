#include <SDL3/SDL.h>
#include "scene_manager.h"

void SceneManager::add_scene(std::unique_ptr<Scene> scene){
    scenes.push_back(std::move(scene));
    if (scenes.size() == 1){
        active_scene = scenes[0].get();
    }
}

void SceneManager::scene_update(InputHandler& input_handler){
    active_scene->update(input_handler);
}

void SceneManager::render_scene(SDL_Renderer& renderer){
    active_scene->render(renderer);
    SDL_RenderPresent(&renderer);
}

