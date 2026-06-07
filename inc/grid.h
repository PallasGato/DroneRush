#pragma once

#include <SDL3/SDL.h>
#include <vector>
#include "game_object.h"
#include "cell.h"

class Grid : public GameObject{
private:
    bool visible;
    uint16_t width;
    uint16_t height;
    float grid_distance;
    std::vector<std::vector<Cell>> cells = {};
    std::vector<SDL_FPoint> grid_point_array = {};

    void set_point_array();
public:
    Grid(uint16_t grid_width, uint16_t grid_height, float grid_step);
    Grid();
    virtual ~Grid() = default;

    void draw(SDL_Renderer& renderer);
};