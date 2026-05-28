#include <main.h>

int main(int argc, char* argv[]) {
    Window main_window;
    EventHandler event_handler;
    Input input;
    main_window.init();
    bool done = false;
    while (!done) {
        event_handler.window_event();
        if (event_handler.is_quit_flag_set()){
            done = true;
            break;
        }
    }
    main_window.shutdown();
    return 0;
}