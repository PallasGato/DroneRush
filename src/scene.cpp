#include "scene.h"

void Scene::render(SDL_Renderer& renderer){
    for (auto& game_object : game_objects){
        game_object->draw(renderer, camera.get_position());
    }
}

void Scene::add_game_object(std::unique_ptr<GameObject> game_object){
    game_objects.push_back(std::move(game_object));
}

Scene::Scene(){ 
    return;
}

const Camera& Scene::get_camera() const{
    return camera;
}

Camera& Scene::get_camera(){
    return camera;
}