#include "frame_timer.h"

void FrameTimer::start_frame(){
    uint64_t frame_start = SDL_GetTicks();
}

void FrameTimer::end_frame(){
    uint64_t frame_time = SDL_GetTicks() - frame_start;
    if (frame_time < FRAME_TIME){
        SDL_Delay(FRAME_TIME - frame_time);
    }
}