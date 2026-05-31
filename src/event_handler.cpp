#include "event_handler.h"

void InputHandler::input_event(){
    SDL_Event event;
    mouse_down_mask = 0;
    mouse_up_mask = 0;
    rel_x = 0;
    rel_y = 0;
    currently_pressed = {};
    currently_released = {};
    while (SDL_PollEvent(&event)){
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            quit_flag = true;
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            mouse_button_down_handler(event);
            break;
        case SDL_EVENT_MOUSE_BUTTON_UP:
            mouse_button_up_handler(event);
            break;
        case SDL_EVENT_MOUSE_MOTION:
            mouse_motion_handler(event);
            break;
        case SDL_EVENT_KEY_DOWN:
            key_down_handler(event);
            break;
        case SDL_EVENT_KEY_UP:
            key_up_handler(event);
            break;
        default:
            break;
        }
    }
}


bool InputHandler::is_quit_flag_set(){
    return quit_flag;
}

//Mouse handlers
void InputHandler::mouse_button_down_handler(const SDL_Event& event){
    mouse_state_mask |= 1u << (event.button.button - 1);
    mouse_down_mask |= 1u << (event.button.button - 1);
}

void InputHandler::mouse_button_up_handler(const SDL_Event& event){
    mouse_state_mask ^= 1u << (event.button.button - 1);
    mouse_up_mask |= 1u << (event.button.button - 1);
}

//Mouse states methods
bool InputHandler::is_button_pressed(MouseButtonMask mouse_flag){
    return mouse_state_mask & mouse_flag;
}

bool InputHandler::is_button_just_pressed(MouseButtonMask mouse_flag){
    return mouse_down_mask & mouse_flag;
}

bool InputHandler::is_button_just_released(MouseButtonMask mouse_flag){
    return mouse_up_mask & mouse_flag;
}

//Mouse motion event
void InputHandler::mouse_motion_handler(const SDL_Event& event){
    x = event.motion.x;
    y = event.motion.y;
    rel_x += event.motion.xrel;
    rel_y += event.motion.yrel;
}

MOUSE_ABSOLUTE_POSITION InputHandler::get_absolute_position(){
    return MOUSE_ABSOLUTE_POSITION{x, y};
}

MOUSE_RELATIVE_POSITION InputHandler::get_relative_position(){
    return MOUSE_RELATIVE_POSITION{rel_x, rel_y};
}

void InputHandler::get_absolute_position(float& absolute_x, float& absolute_y){
    absolute_x = x;
    absolute_y = y;
}
void InputHandler::get_relative_position(float& relative_x, float& relative_y){
    relative_x = rel_x;
    relative_y = rel_y;
}

//Key handlers
void InputHandler::key_down_handler(const SDL_Event& event){
    currently_pressed[event.key.scancode] = !event.key.repeat;
    current_keys[event.key.scancode] = true;
}

void InputHandler::key_up_handler(const SDL_Event& event){
    current_keys[event.key.scancode] = false;
    currently_released[event.key.scancode] = true;
}

//Keyboard states methods
bool InputHandler::is_key_pressed(SDL_Scancode key){
    return current_keys[key];
}

bool InputHandler::is_key_just_pressed(SDL_Scancode key){
    return currently_pressed[key];
}

bool InputHandler::is_key_just_released(SDL_Scancode key){
    return currently_released[key];
}