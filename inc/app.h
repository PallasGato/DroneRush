#pragma once
#include "window_manager.h"
#include "event_handler.h"
#include "frame_timer.h"

class App{
private: 
    Window window;
    InputHandler input_handler;
    FrameTimer frame_timer;
    bool quit = false;

    void process_event_flags();

public:
    bool init();
    void run();
    void render();
    void shutdown();
};