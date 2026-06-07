#include "scene.h"

void Scene::render(SDL_Renderer& renderer){
    for (auto& game_object : game_objects){
        game_object->draw(renderer, view_position);
    }
}

void Scene::add_game_object(std::unique_ptr<GameObject> game_object){
    game_objects.push_back(std::move(game_object));
}

void Scene::add_view_position(Vector2DF position_change){
    view_position += position_change;
}

Scene::Scene(){ 
    return;
}
