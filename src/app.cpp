#include "app.h"

bool App::init(){
    return main_window.init();
}

void App::run(){
    while (!done) {
        frame_timer.start_frame();
        event_handler.window_event();
        if (event_handler.is_quit_flag_set()){
            done = true;
        }
        frame_timer.end_frame();
    }
}

void App::shutdown() {
    main_window.shutdown();
}