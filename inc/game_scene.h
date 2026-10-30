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


class GameScene: public Scene{
private:
    Grid* grid = nullptr;
    //Инициализация ячеек с невалидными координатами.
    //Ячейка по умолчанию и невалидная
    Cell on_hover_cell = Cell(-1, -1, false);
    Cell last_valid_cell = Cell(-1, -1, false);
    
    //Инициализация объекта подсветки ячейки
    Rectangle* highlight = nullptr;

    //Пул выделенных юнитов
    std::list<Unit*> selected_units;
public:
    GameScene();
    void update(InputHandler& input_handler);
    ~GameScene();
};