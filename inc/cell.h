#pragma once
#include "terrain.h"
#include "geometry.h"
#include <SDL3/SDL.h>
#include <list>

class Unit;

class Cell{
private:
    int x;
    int y;
    bool valid;
    SDL_FRect* terrain_rect;
    Vector2DF world_position;
    Terrain terrain;
    //Список юнитов, которые находятся в ячейке
    std::list<Unit*> occupants;
public:
    Cell();
    Cell(int x, int y);
    Cell(int x, int y, bool is_valid);
    Cell(int x, int y, bool is_valid, Vector2DF world_position);
    bool is_valid();

    void get_coordinates(Vector2DF& hover_coordinates);
    void get_coordinates(int& hover_x, int& hover_y);
    void set_world_position(const Vector2DF& position);
    Vector2DF get_world_position() const;

   std::list<Unit*> get_occupant() const;
    void set_occupant(Unit* unit);

    void set_terrain(const Terrain& terrain);
    void set_terrain_rect(SDL_FRect* rect);

    Cell& operator=(const Cell& other);
};


