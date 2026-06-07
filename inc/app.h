#pragma once
#include "window_manager.h"
#include "input_handler.h"
#include "frame_timer.h"
#include "scene_manager.h"
#include "game_scene.h"
class App{
private:
    SDL_Renderer* renderer;
    Window window;
    InputHandler input_handler;
    FrameTimer frame_timer;
    SceneManager scene_manager;
    bool quit = false;

    void process_event_flags();

public:
    ~App();
    bool init();
    void run();
    void render();
    void shutdown();
};