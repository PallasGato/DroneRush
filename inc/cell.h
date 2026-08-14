#pragma once
#include "terrain.h"
#include "geometry.h"
class Cell{
private:
    int x;
    int y;
    Terrain terrain;
    Vector2DF world_position;
public:
    Cell();
    Cell(int x, int y);
    void get_coordinates(int& hover_x, int& hover_y);
    void set_world_position(const Vector2DF& position);
    Vector2DF get_world_position() const { return world_position; }
    Cell& operator=(const Cell& other);
};


