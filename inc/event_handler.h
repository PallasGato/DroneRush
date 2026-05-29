#pragma once 

#include <SDL3/SDL.h>

class EventHandler{
private:
    int scancodes;
    bool quit_flag = false;
public:
    void window_event();
    bool is_quit_flag_set();
    
};