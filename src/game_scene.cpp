#include "game_scene.h"

GameScene::GameScene(){
    auto grid = std::make_unique<Grid>(32, 32, 64);
    add_game_object(std::move(grid));
}

void GameScene::update(InputHandler& input_handler){
    return;
}

GameScene::~GameScene() = default;