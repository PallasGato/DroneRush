#include "grid.h"

// Constructor for the grid class. Initializes the grid with the specified width,
// height, and distance between grid points.
Grid::Grid(uint16_t grid_width, uint16_t grid_height, float grid_step){
    width = grid_width;
    height = grid_height;
    grid_distance = grid_step;
    visible = true;
    cells.resize(height, std::vector<Cell>(width));
    set_point_arrays();
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
void Grid::set_point_arrays(){
    grass_rectangles.reserve(width * height);
    float x = 0;
    for (int x_grid = 0; x_grid < width; x_grid++){
        float y = 0;
        for (int y_grid = 0; y_grid < height; y_grid++){
            grid_point_array.push_back(SDL_FPoint{x, y});
            cells[x_grid][y_grid] = Cell(x_grid, y_grid);
            cells[x_grid][y_grid].set_world_position(Vector2DF{x, y});

            //Задание тайла травы для каждой ячейки сетки
            cells[x_grid][y_grid].set_terrain(grass);
            grass_rectangles.push_back(SDL_FRect{x, y, grid_distance, grid_distance});    
            //Ячейка хранит указатель на собственный прямоугольник
            cells[x_grid][y_grid].set_terrain_rect(&grass_rectangles.back());
            y += grid_distance;
        }
        x += grid_distance;
    }
}


Cell& Grid::snap_to_grid(const Vector2DF& position){
    int x_grid = static_cast<int>(position.x / grid_distance);
    int y_grid = static_cast<int>(position.y / grid_distance);
    int negative_pos = static_cast<int>(position.x) | static_cast<int>(position.y);
    if (x_grid >= 0 &&
        x_grid < width &&
        y_grid >= 0 &&
        y_grid < height
        && negative_pos >= 0){
        return cells[x_grid][y_grid];
    }
    // If the position is out of bounds, return a default cell with invalid coordinates.
    return invalid_cell; 
}

// Draws the grid on the screen using SDL_RenderPoints. The grid points are rendered in green color.
void Grid::draw(SDL_Renderer& renderer, const Vector2DF& view_position){
    //Отрисовка сетки в виде прямоугольников
    std::vector<SDL_FRect> transformed_rectangles = grass_rectangles;
    world_to_screen(transformed_rectangles, view_position);
    SDL_SetRenderDrawColor(&renderer, 0, 173, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRects(&renderer, transformed_rectangles.data(), transformed_rectangles.size());
    //Отрисовка сетки в виде точек для отладки
    std::vector<SDL_FPoint> transformed_points = grid_point_array;
    world_to_screen(transformed_points, view_position);
    SDL_SetRenderDrawColor(&renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderPoints(&renderer, transformed_points.data(), transformed_points.size());
}