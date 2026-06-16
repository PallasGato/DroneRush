#pragma once

#include <SDL3/SDL.h>
#include "scene.h"
#include "geometry.h"
#include "input_handler.h"

class GameScene: public Scene{
private:
    
public:
    GameScene();
    void update(InputHandler& input_handler);
    ~GameScene();
};