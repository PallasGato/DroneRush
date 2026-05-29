#include "event_handler.h"

void EventHandler::window_event(){
    mouse_flags = 0;
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            quit_flag = true;
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            mouse_button_down_handler(&event);
            break;
        default:
            break;
        }
    }
}


bool EventHandler::is_quit_flag_set(){
    return quit_flag;
}

void EventHandler::mouse_button_down_handler(SDL_Event* event){
    mouse_flags |= event->button.button;
}

bool EventHandler::is_button_pressed(SDL_MouseButtonFlags mouse_flag){
    return mouse_flags == mouse_flag;
}