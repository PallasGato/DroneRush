#pragma once
#include "terrain.h"
#include "geometry.h"
#include "unit.h"
#include <SDL3/SDL.h>

class Unit;

class Cell{
private:
    int x;
    int y;
    bool valid;
    SDL_FRect* terrain_rect;
    Vector2DF world_position;
    Terrain terrain;
    Unit* occupant = nullptr;
public:
    Cell();
    Cell(int x, int y);
    Cell(int x, int y, bool is_valid);
    bool is_valid();

    void get_coordinates(Vector2DF& hover_coordinates);
    void get_coordinates(int& hover_x, int& hover_y);
    void set_world_position(const Vector2DF& position);
    Vector2DF get_world_position() const;

    void set_terrain(const Terrain& terrain);
    void set_terrain_rect(SDL_FRect* rect);

    Cell& operator=(const Cell& other);
};


