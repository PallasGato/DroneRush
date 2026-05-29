#include "SDL3/SDL.h"

class FrameTimer{
public:
    void start_frame();
    void end_frame();
private:
    uint64_t frame_start;
    static constexpr uint64_t FRAME_TIME = 17;
};