#include "scene.h"

void Scene::render(SDL_Renderer& renderer){
    for (auto& game_object : game_objects){
        game_object->draw(renderer);
    }
}

Scene::Scene(){ 
    return;
}
