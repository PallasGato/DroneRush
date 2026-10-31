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

    Cell invalid_cell = Cell(-1, -1, false, Vector2DF{-1.0, -1.0});
    Cell* on_hover_cell = &invalid_cell;
    Cell* last_valid_cell = &invalid_cell;
    
    //Инициализация объекта подсветки ячейки
    Rectangle* highlight = nullptr;

    //Пул выделенных юнитов
    std::list<Unit*> selected_units;
    //Пул перемещающихся юнитов
    std::list<Unit*> moving_units;
    
    //Метод для выделения юнита по клику мыши
    void unit_selection(InputHandler& input_handler, Cell& cell);
    void cell_targeting(InputHandler& input_handler, Cell& cell);

    void move_units();
public:
    GameScene();
    void update(InputHandler& input_handler);
    ~GameScene();
};