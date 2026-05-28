#include "window_manager.h"

bool Window::init(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "SDL_INIT FAILED: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
        "An SDL3 window",                  // window title
        WINDOW_W,                               // width, in pixels
        WINDOW_H,                               // height, in pixels
        0                  // flags - see below
    );
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }
    return 0;
}

void Window::shutdown(){
    if (window){
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

SDL_Window* Window::get_window() const{
    return window;
}