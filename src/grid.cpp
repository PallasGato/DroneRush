#include "grid.h"

// Constructor for the grid class. Initializes the grid with the specified x_size,
// y_size, and distance between grid points.
Grid::Grid(uint16_t x_size, uint16_t y_size, float grid_step){
    this->x_size = x_size;
    this->y_size = y_size;
    this->grid_distance = grid_step;
    this->visible = true;
    cells.resize(y_size, std::vector<Cell>(x_size));
    set_point_arrays();
    define_terrain_colors();
}


Grid::Grid(){
    position = {0, 0};
    this->x_size = 0;
    this->y_size = 0;
    this->grid_distance = 0;
    this->visible = true;
    define_terrain_colors();
}

void Grid::define_terrain_colors(){
    grass.set_color(Palette{0, 173, 0, SDL_ALPHA_OPAQUE});
}

// Array of points for grid.
// Made for rendering debug points.
// Later coordinates will be used to place game objects on the grid.
void Grid::set_point_arrays(){
    grass_rectangles.reserve(x_size * y_size);
    float x = 0;
    for (int x_grid = 0; x_grid < x_size; x_grid++){
        float y = 0;
        for (int y_grid = 0; y_grid < y_size; y_grid++){
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
        x_grid < x_size &&
        y_grid >= 0 &&
        y_grid < y_size
        && negative_pos >= 0){
        return cells[x_grid][y_grid];
    }
    // If the position is out of bounds, return a default cell with invalid coordinates.
    return invalid_cell; 
}

// Draws the grid on the screen using SDL_RenderPoints. The grid points are rendered in green color.
void Grid::draw(SDL_Renderer& renderer, const Vector2DF& view_position){
    //Отрисовка сетки в виде прямоугольников для тайлов травы
    std::vector<SDL_FRect> transformed_rectangles = grass_rectangles;
    Palette grass_color = grass.get_color();
    world_to_screen(transformed_rectangles, view_position);
    SDL_SetRenderDrawColor(&renderer, grass_color.r, grass_color.g, grass_color.b, grass_color.a);
    SDL_RenderFillRects(&renderer, transformed_rectangles.data(), transformed_rectangles.size());

    //Отрисовка сетки в виде точек для отладки
    std::vector<SDL_FPoint> transformed_points = grid_point_array;
    world_to_screen(transformed_points, view_position);
    SDL_SetRenderDrawColor(&renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderPoints(&renderer, transformed_points.data(), transformed_points.size());
}