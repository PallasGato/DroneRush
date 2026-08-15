#include "game_scene.h"

GameScene::GameScene(){ 
    auto grid_object = std::make_unique<Grid>(32, 32, 32);
    grid = grid_object.get();
    add_game_object(std::move(grid_object));

    auto highlight_object = std::make_unique<Rectangle>(0, 0, 32, 32, 
                                        Palette{127, 127, 127, 2});
    highlight = highlight_object.get();
    add_ui_object(std::move(highlight_object));
}


//Method to update current game state
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

    on_hover_cell = grid->snap_to_grid(mouse_to_world_position);
    //Проверка на валидность полученной в текущем фрейме ячейки
    if (!on_hover_cell.is_valid()){
        on_hover_cell = last_valid_cell;
    }
    last_valid_cell = on_hover_cell;
    Vector2DF hover_position = on_hover_cell.get_world_position();
    highlight->set_position(world_to_screen(hover_position, get_camera().get_position()));
    //Returning from the function (seems obvious to comment)
    return;
}

GameScene::~GameScene() = default;