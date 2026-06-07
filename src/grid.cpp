#include "grid.h"

// Constructor for the grid class. Initializes the grid with the specified width,
// height, and distance between grid points.
Grid::Grid(uint16_t grid_width, uint16_t grid_height, float grid_step){
    width = grid_width;
    height = grid_height;
    grid_distance = grid_step;
    visible = true;
    set_point_array();
}


Grid::Grid(){
    position = {0, 0};
    width = 0;
    height = 0;
    grid_distance = 0;
    visible = true;
}
// Array of points for grid.
// Made for rendering debug points.
// Later coordinates will be used to place game objects on the grid.
void Grid::set_point_array(){
    float y = 0;
    for (int row = 0; row < height; row++){
        float x = 0;
        for (int col = 0; col < width; col++){
            grid_point_array.push_back(SDL_FPoint{x, y});
            x += grid_distance;
        }
        y += grid_distance;
    }
}


// Draws the grid on the screen using SDL_RenderPoints. The grid points are rendered in green color.
void Grid::draw(SDL_Renderer& renderer, Vector2DF view_position){
    std::vector<SDL_FPoint> transformed_points = grid_point_array;
    for (auto& point : transformed_points) {
        point.x += view_position.x;
        point.y += view_position.y;
    }
    SDL_SetRenderDrawColor(&renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderPoints(&renderer, transformed_points.data(), transformed_points.size());
}