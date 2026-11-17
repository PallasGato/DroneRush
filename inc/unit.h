#pragma once

#include <list>
#include <SDL3/SDL.h>
#include "game_object.h"
#include "geometry.h"

// Forward declarations only: these are used as pointers/references.
class Cell;
class Grid;


class Unit: public GameObject{
private:
    //Информация о текущей ячейке, в которой находится юнит
    Cell* current_cell = nullptr;
    int x_cell = 0;
    int y_cell = 0;

    //Размер юнита, чтобы определять место, которое он занимает
    //Пока размер не превышает размер ячейки
    float size = 8.0f;
    float bounding_circle_size = 2.0f;
    //Информация о текущей позиции юнита в мировых координатах
    Vector2DF world_position = {0, 0};

    Vector2DF target_position = {0, 0};

    std::list<Cell*> surrounding_cells = {};
    //Выбран ли юнит
    bool selected = false;
    bool moving = false;

public:
    Unit();
    ~Unit() = default;
    void draw(SDL_Renderer& renderer, const Vector2DF& view_position) override;
    void change_visibility(bool visibility);
    void set_position(Vector2DF position);
    void set_target_position(Vector2DF position, std::list<Unit*>& moving_units);
    void change_target_position(Vector2DF position);

    bool move(Grid& grid);
    bool is_moving() const;
    void set_moving(bool is_moving);

    bool is_selected() const;
    void set_selection(bool selection);
};