#pragma once
#include "terrain.h"
#include "geometry.h"
class Cell{
private:
    int x;
    int y;
    bool valid;
    Terrain terrain;
    Vector2DF world_position;
public:
    Cell();
    Cell(int x, int y);
    Cell(int x, int y, bool is_valid);

    bool is_valid();

    void get_coordinates(Vector2DF& hover_coordinates);
    void get_coordinates(int& hover_x, int& hover_y);
    void set_world_position(const Vector2DF& position);
    Vector2DF get_world_position() const { return world_position; }
    Cell& operator=(const Cell& other);
};


