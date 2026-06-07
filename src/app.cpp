#include "app.h"

bool App::init(){
    if (!window.init()){
        renderer = window.get_renderer();
        return 0;
    }
    return 1;
}

void App::run(){
    // Add the game scene to the scene manager
    auto game_scene = std::make_unique<GameScene>();
    scene_manager.add_scene(std::move(game_scene));
    // Main loop
    while (!quit) {
        frame_timer.start_frame();
        input_handler.input_event();
        process_event_flags();
        scene_manager.scene_update(input_handler);
        scene_manager.render_scene(*renderer);
        frame_timer.end_frame();
    }
}

void App::shutdown() {
    window.shutdown();
}

void App::process_event_flags(){
    if (input_handler.is_quit_flag_set()){
        quit = true;
    }
}

App::~App() = default;