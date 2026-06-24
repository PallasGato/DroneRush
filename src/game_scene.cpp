#include "game_scene.h"

GameScene::GameScene(){ 
    auto grid_object = std::make_unique<Grid>(256, 256, 32);
    grid = grid_object.get();
    add_game_object(std::move(grid_object));
}

void GameScene::update(InputHandler& input_handler){
    //Changing camera position with WASD keys
    if (input_handler.is_key_pressed(SDL_SCANCODE_W)){
        get_camera().move(0, -10);
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_S)){
        get_camera().move(0, 10);
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_A)){
        get_camera().move(-10, 0);
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_D)){
        get_camera().move(10, 0);
    }

    //Getting mouse position and converting it to world coordinates
    Vector2DF mouse_position = input_handler.get_absolute_position();
    Vector2DF mouse_to_world_position = get_camera().point_to_world(mouse_position);

    //Getting cell according to mouse position and logging it
    int row, col;
    on_hover_cell = grid->snap_to_grid(mouse_to_world_position);
    on_hover_cell.get_coordinates(row, col);
    SDL_Log("Row:%d\tCol:%d", row, col);

    //Returning from the function (seems obvious to comment)
    return;
}

GameScene::~GameScene() = default;