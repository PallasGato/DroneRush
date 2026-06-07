#pragma once

#include <list>
#include <SDL3/SDL.h>
#include <memory>
#include "game_object.h"
#include "grid.h"
#include "input_handler.h"

class Scene{
private:
    std::list<std::unique_ptr<GameObject>> game_objects = {};
public:
    Scene();
    void add_game_object(std::unique_ptr<GameObject> game_object){
        game_objects.push_back(std::move(game_object));
    }
    virtual void update(InputHandler& input_handler){
        return;
    }
    virtual ~Scene() = default;
    virtual void render(SDL_Renderer& renderer);
};