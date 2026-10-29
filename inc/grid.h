#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include "game_object.h"
#include "cell.h"
#include "geometry.h"
#include "terrain.h"


class Grid : public GameObject{
private:
    bool visible;
    uint16_t width;
    uint16_t height;
    float grid_distance;

    Terrain grass = Terrain(TerrainType::Grass, ResourceType::None);
    std::vector<SDL_FRect> grass_rectangles = {};

    std::vector<std::vector<Cell>> cells = {};
    std::vector<SDL_FPoint> grid_point_array = {};
    Cell invalid_cell = Cell(-1, -1, false);
    void set_point_arrays();
    void define_terrain_colors();
public:
    Grid(uint16_t grid_width, uint16_t grid_height, float grid_step);
    Grid();
    virtual ~Grid() = default;

    Cell& snap_to_grid(const Vector2DF& position);
    void draw(SDL_Renderer& renderer, const Vector2DF& view_position);
};