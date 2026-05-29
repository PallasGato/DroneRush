#include "app.h"

bool App::init(){
    return main_window.init();
}

void App::run(){
    while (!done) {
        uint64_t frame_start = SDL_GetTicks();
        event_handler.window_event();
        if (event_handler.is_quit_flag_set()){
            done = true;
        }
        uint64_t frame_time = SDL_GetTicks() - frame_start;
        if (frame_time < FRAME_TIME){
            SDL_Delay(FRAME_TIME - frame_time);
        }
    }
}

void App::shutdown() {
    main_window.shutdown();
}