#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include <list>
#include "game_object.h"
#include "cell.h"
#include "geometry.h"
#include "terrain.h"
#include "MACRO.h"


class Grid : public GameObject{
private:
    bool visible;
    uint16_t x_size;
    uint16_t y_size;
    float grid_distance;

    Terrain grass = Terrain(TerrainType::Grass, ResourceType::None);
    std::vector<SDL_FRect> grass_rectangles = {};

    std::vector<std::vector<Cell>> cells = {};
    std::vector<SDL_FPoint> grid_point_array = {};
    Cell invalid_cell = Cell(-1, -1, false);
    void set_point_arrays();
    void define_terrain_colors();
public:
    Grid(uint16_t x_size, uint16_t y_size, float grid_step);
    Grid();
    ~Grid() = default;

    Cell& snap_to_grid(const Vector2DF& position);
    std::list<Cell*> get_surroundings(const Vector2DF& position, float radius);
    Cell& get_cell(int x, int y);
    void draw(SDL_Renderer& renderer, const Vector2DF& view_position);

};