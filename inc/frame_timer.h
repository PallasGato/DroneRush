#pragma once
#include "SDL3/SDL.h"

class FrameTimer{
public:
    void start_frame();
    void end_frame();
    float get_delta();

    FrameTimer();

private:
    uint64_t frame_start;
    uint64_t previous_frame_start;
    static constexpr uint64_t FRAME_TIME = 16;
};