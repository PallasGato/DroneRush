#include "app.h"

bool App::init(){
    return window.init();
}

void App::run(){
    int frame = 0;
    while (!quit) {
        frame_timer.start_frame();
        event_handler.window_event();
        SDL_Log("Frame %d", frame);
        if (event_handler.is_key_just_pressed(SDL_SCANCODE_A))
            SDL_Log("A released!");
        if (event_handler.is_button_just_released(LEFT_MOUSE_BUTTON))
            SDL_Log("LMB pressed!");
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