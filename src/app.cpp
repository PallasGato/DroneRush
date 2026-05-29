#include "app.h"

bool App::init(){
    return window.init();
}

void App::run(){
    while (!quit) {
        frame_timer.start_frame();
        event_handler.window_event();
        process_event_flags();
        render();
        frame_timer.end_frame();
    }
}

void App::shutdown() {
    window.shutdown();
}

void App::process_event_flags(){
    if (event_handler.is_quit_flag_set()){
        quit = true;
    }
}

void App::render(){
    SDL_Renderer* renderer_p = window.get_renderer();
    SDL_SetRenderDrawColor(renderer_p, 255, 255, 255, 255);
    SDL_RenderClear(renderer_p);
    SDL_FRect rectangle{
        100.f,
        100.f,
        50.f,
        50.f
    };
    SDL_SetRenderDrawColor(renderer_p, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer_p, &rectangle);
    SDL_RenderPresent(renderer_p);
}