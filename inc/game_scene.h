#pragma once

#include <SDL3/SDL.h>
#include "scene.h"
#include "geometry.h"
#include "input_handler.h"
#include "game_object.h"
#include "grid.h"
#include "ui_object.h"
#include "palette.h"

class GameScene: public Scene{
private:
    Grid* grid = nullptr;
    Cell on_hover_cell = Cell(-1, -1);
    Rectangle* highlight = nullptr;
public:
    GameScene();
    void update(InputHandler& input_handler);
    ~GameScene();
};