#include "frame_timer.h"

void FrameTimer::start_frame(){
    frame_start = SDL_GetTicks();
}

void FrameTimer::end_frame(){
    uint64_t frame_time = SDL_GetTicks() - frame_start;
    if (frame_time < FRAME_TIME){
        SDL_Delay(FRAME_TIME - frame_time);
    }
    previous_frame_start = frame_start;
}

float FrameTimer::get_delta(){
    float frame_time = 
    static_cast<float>(SDL_GetTicks() - previous_frame_start);
    return frame_time;
}

FrameTimer::FrameTimer(){
    previous_frame_start = SDL_GetTicks();
}