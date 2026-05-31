#include "event_handler.h"

void EventHandler::window_event(){
    SDL_Event event;
    mouse_down_mask = 0;
    mouse_up_mask = 0;
    previous_keys = current_keys;
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


bool EventHandler::is_quit_flag_set(){
    return quit_flag;
}

//Mouse handlers
void EventHandler::mouse_button_down_handler(const SDL_Event& event){
    mouse_state_mask |= 1u << (event.button.button - 1);
    mouse_down_mask |= 1u << (event.button.button - 1);
}

void EventHandler::mouse_button_up_handler(const SDL_Event& event){
    mouse_state_mask ^= 1u << (event.button.button - 1);
    mouse_up_mask |= 1u << (event.button.button - 1);
}

//Mouse states methods
bool EventHandler::is_button_pressed(MouseButtonMask mouse_flag){
    return mouse_state_mask & mouse_flag;
}

bool EventHandler::is_button_just_pressed(MouseButtonMask mouse_flag){
    return mouse_down_mask & mouse_flag;
}

bool EventHandler::is_button_just_released(MouseButtonMask mouse_flag){
    return mouse_up_mask & mouse_flag;
}

//Key handlers
void EventHandler::key_down_handler(const SDL_Event& event){
    current_keys[event.key.scancode] = true;
}

void EventHandler::key_up_handler(const SDL_Event& event){
    current_keys[event.key.scancode] = false;
}

//Keyboard states methods
bool EventHandler::is_key_pressed(SDL_Scancode key){
     return current_keys[key];
}

bool EventHandler::is_key_just_pressed(SDL_Scancode key){
    return current_keys[key] && !previous_keys[key];
}

bool EventHandler::is_key_just_released(SDL_Scancode key){
    return !current_keys[key] && previous_keys[key];
}