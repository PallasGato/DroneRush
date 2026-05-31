#pragma once 

#include <SDL3/SDL.h>

using MouseButtonMask = uint8_t;

#define LEFT_MOUSE_BUTTON 1
#define MIDDLE_MOUSE_BUTTON 2
#define RIGHT_MOUSE_BUTTON 4

class EventHandler{
private:
    int scancodes;
    bool quit_flag = false;
    float mouse_x, mouse_y;
    MouseButtonMask mouse_state_mask = 0, mouse_down_mask, mouse_up_mask;
    void mouse_button_down_handler(const SDL_Event& event);
    void mouse_button_up_handler(const SDL_Event& event);
public:
    void window_event();
    bool is_quit_flag_set();
    bool is_button_pressed(MouseButtonMask mous_state_flag);
    bool is_button_just_pressed(MouseButtonMask mous_state_flag);
    bool is_button_just_released(MouseButtonMask mous_state_flag);
};