#include "window_manager.h"

bool Window::init(){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to initialize window: %s\n", SDL_GetError());
        return 1;
    }
    window = SDL_CreateWindow(
        "Drone Rush!",
        WINDOW_W,
        WINDOW_H,
        0
    );
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to create window: %s\n", SDL_GetError());
        return 1;
    }
    renderer = SDL_CreateRenderer(window, 0);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to create renderer: %s\n", SDL_GetError());
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

SDL_Renderer* Window::get_renderer() const{
    return renderer;
}