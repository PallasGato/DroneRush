#include "game_scene.h"

GameScene::GameScene(){
    auto grid = std::make_unique<Grid>(32, 32, 64);
    add_game_object(std::move(grid));
}

void GameScene::update(InputHandler& input_handler){
    if (input_handler.is_key_pressed(SDL_SCANCODE_W)){
        add_view_position({0, 10});
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_S)){
        add_view_position({0, -10});
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_A)){
        add_view_position({10, 0});
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_D)){
        add_view_position({-10, 0});
    }
    return;
}

GameScene::~GameScene() = default;