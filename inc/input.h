#pragma once 

#include <SDL3/SDL.h>

class Input{
private:
    const bool* scancode_map;
public:
    bool is_key_pressed(SDL_Scancode scancode);
    Input();
};