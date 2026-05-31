#include "input.h"

Input::Input(){
    int keyboard_key_num;
    scancode_map = SDL_GetKeyboardState(&keyboard_key_num);


}

bool Input::is_key_pressed(SDL_Scancode scancode){
    return scancode_map[scancode];
}

// void Input::get_mouse_state(){
//     previous_mouse_buttons = mouse_buttons;
//     mouse_buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
// }

// bool Input::is_button_pressed(MouseButtonMask mouse_flag){
//     return mouse_buttons == mouse_flag;
// }

// bool Input::is_button_just_pressed(MouseButtonMask mouse_flag){
//     return (mouse_buttons == mouse_flag) && (previous_mouse_buttons != mouse_flag);
// }