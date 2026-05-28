#pragma once

#include <SDL3/SDL.h>

class Window{
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    static constexpr int WINDOW_W = 1024;
    static constexpr int WINDOW_H = 768;
public:
    bool init();
    void shutdown();
    SDL_Window* get_window() const;
};
