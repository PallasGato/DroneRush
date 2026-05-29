#pragma once
#include "window_manager.h"
#include "event_handler.h"
#include "input.h"
#include "frame_timer.h"

class App{
private: 
    Window main_window;
    EventHandler event_handler;
    Input input;
    FrameTimer frame_timer;
    bool done = false;
public:
    bool init();
    void run();
    void shutdown();
};