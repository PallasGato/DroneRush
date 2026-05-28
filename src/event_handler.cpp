#include "event_handler.h"

void EventHandler::window_event(){
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_EVENT_QUIT:
        quit_flag = true;
        break;
    default:
        break;
    }
}


bool EventHandler::is_quit_flag_set(){
    return quit_flag;
}


