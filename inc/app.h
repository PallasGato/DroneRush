#pragma once
#include <SDL3/SDL.h>
#include "window_manager.h"
#include "event_handler.h"
#include "input.h"

class App{
private: 
    Window main_window;
    EventHandler event_handler;
    Input input;
    static constexpr uint64_t FRAME_TIME = 17;
    bool done = false;
public:
    bool init();
    void run();
    void shutdown();
};