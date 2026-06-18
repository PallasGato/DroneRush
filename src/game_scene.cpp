#include "game_scene.h"

GameScene::GameScene(){ 
    auto grid_object = std::make_unique<Grid>(256, 256, 32);
    grid = grid_object.get();
    add_game_object(std::move(grid_object));
}

void GameScene::update(InputHandler& input_handler){
    if (input_handler.is_key_pressed(SDL_SCANCODE_W)){
        add_view_position({0, -10});
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_S)){
        add_view_position({0, 10});
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_A)){
        add_view_position({-10, 0});
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_D)){
        add_view_position({10, 0});
    }
    Vector2DF mouse_position = input_handler.get_absolute_position();
    Vector2DF mouse_to_world_position = screen_to_world(mouse_position, get_view_position());
    on_hover_cell = grid->snap_to_grid(mouse_to_world_position);
    int row = 0, col = 0;
    on_hover_cell.get_coordinates(row, col);
    SDL_Log("Row:%d\tCol:%d", row, col);
    return;
}

GameScene::~GameScene() = default;