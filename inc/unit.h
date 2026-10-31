#pragma once

#include <list>
#include <SDL3/SDL.h>
#include "game_object.h"
#include "cell.h"
#include "geometry.h"

//Так называемый блять как это без смотря какой fabric написать
//Объявление в долг короче.
class Cell;

class Unit: public GameObject{
private:
    //Информация о текущей ячейке, в которой находится юнит
    Cell* current_cell = nullptr;
    int x_cell = 0;
    int y_cell = 0;

    //Информация о целевой ячейке, в которую юнит должен переместиться
    Cell* target_cell = nullptr;
    int target_x_cell = 0;
    int target_y_cell = 0;

    //Информация о текущей позиции юнита в мировых координатах
    Vector2DF world_position = {0, 0};

    //Выбран ли юнит
    bool selected = false;

public:
    Unit();
    ~Unit() = default;
    void draw(SDL_Renderer& renderer, const Vector2DF& view_position) override;
    void change_visibility(bool visibility);
    void set_current_cell(Cell* cell);
    void set_target_cell(Cell* cell);
    void set_target_cell(Cell* cell, std::list<Unit*>& moving_units);

    bool move();

    bool is_selected() const;
    void set_selection(bool selection);
};