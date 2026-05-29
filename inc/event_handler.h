#pragma once 

#include <SDL3/SDL.h>

class EventHandler{
private:
    int scancodes;
    bool quit_flag = false;
    float mouse_x, mouse_y;
    SDL_MouseButtonFlags previous_mouse_flags;
    SDL_MouseButtonFlags mouse_flags;
    void mouse_button_down_handler(SDL_Event* event);
public:
    void window_event();
    bool is_quit_flag_set();
    bool is_button_pressed(SDL_MouseButtonFlags mouse_flag);
};