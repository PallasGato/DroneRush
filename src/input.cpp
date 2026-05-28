#include "input.h"

Input::Input(){
    int keyboard_key_num;
    scancode_map = SDL_GetKeyboardState(&keyboard_key_num);
}

bool Input::is_key_pressed(SDL_Scancode scancode){
    return scancode_map[scancode];
}