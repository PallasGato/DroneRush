#include "scene.h"

void Scene::render(SDL_Renderer& renderer){
    for (auto& game_object : game_objects){
        game_object->draw(renderer, camera.get_position());
    }
    for (int ui_object = 0; ui_object < ui_objects.size(); ui_object++){
        ui_objects[ui_object]->draw(renderer);
    }
}

void Scene::add_game_object(std::unique_ptr<GameObject> game_object){
    game_objects.push_back(std::move(game_object));
}

void Scene::add_ui_object(std::unique_ptr<UIobject> ui_object){
    ui_objects.push_back(std::move(ui_object));
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