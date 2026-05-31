#pragma once 

#include <SDL3/SDL.h>



class Input{
private:
    const bool* scancode_map;
    float mouse_x, mouse_y;
public:
    bool is_key_pressed(SDL_Scancode scancode);
    void get_mouse_state();
    Input();
};