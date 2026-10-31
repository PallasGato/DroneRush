#pragma once

#include <list>
#include <SDL3/SDL.h>
#include "scene.h"
#include "geometry.h"
#include "input_handler.h"
#include "game_object.h"
#include "grid.h"
#include "ui_object.h"
#include "palette.h"
#include "unit.h"
#include "unit_manager.h"

class GameScene: public Scene{
private:
    Grid* grid = nullptr;
    //Инициализация ячеек с невалидными координатами.
    //Ячейка по умолчанию и невалидная

    Cell invalid_cell = Cell(-1, -1, false, Vector2DF{-1.0, -1.0});
    Cell* on_hover_cell = &invalid_cell;
    Cell* last_valid_cell = &invalid_cell;
    
    //Инициализация объекта подсветки ячейки
    Rectangle* highlight = nullptr;

    //Инициализация менеджера юнитов
    UnitManager unit_manager = UnitManager(*input_handler);
public:
    GameScene(InputHandler& input_handler);
    void update(float delta_time);
    ~GameScene();
};