#include <main.h>

int main(int argc, char* argv[]) {
    Window main_window;
    main_window.init();
    bool done = false;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }
    }
    main_window.shutdown();
    return 0;
}