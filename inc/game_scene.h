#pragma once

#include <SDL3/SDL.h>
#include "scene.h"

class GameScene: public Scene{
private:
public:
    GameScene();
    void update(InputHandler& input_handler);
    ~GameScene();
};