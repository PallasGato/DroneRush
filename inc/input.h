#pragma once 

#include <SDL3/SDL.h>

class Input{
private:
    const bool* scancode_map;
    SDL_MouseButtonFlags mouse_buttons;
    SDL_MouseButtonFlags previous_mouse_buttons;
    float mouse_x, mouse_y;
public:
    bool is_key_pressed(SDL_Scancode scancode);
    void get_mouse_state();
    bool is_button_pressed(SDL_MouseButtonFlags mouse_flag);
    bool is_button_just_pressed(SDL_MouseButtonFlags mouse_flag);
    Input();
};