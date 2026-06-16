#pragma once 

#include <SDL3/SDL.h>
#include <array>
#include "geometry.h"

using MouseButtonMask = uint8_t;

#define LEFT_MOUSE_BUTTON 1
#define MIDDLE_MOUSE_BUTTON 2
#define RIGHT_MOUSE_BUTTON 4


class InputHandler{
private:
    bool quit_flag = false;
    float mouse_x, mouse_y;
    //Mouse state masks
    MouseButtonMask mouse_state_mask = 0;
    MouseButtonMask mouse_down_mask = 0;
    MouseButtonMask mouse_up_mask = 0;
    //Mouse coordinates
    float x, y;
    float rel_x, rel_y;
    //Mouse handlers
    void mouse_button_down_handler(const SDL_Event& event);
    void mouse_button_up_handler(const SDL_Event& event);
    void mouse_motion_handler(const SDL_Event& event);

    //keyboard keys state
    std::array<bool, SDL_SCANCODE_COUNT> current_keys{};
    std::array<bool, SDL_SCANCODE_COUNT> currently_pressed{};
    std::array<bool, SDL_SCANCODE_COUNT> currently_released{};
    //Keyboard handlers
    void key_down_handler(const SDL_Event& event);
    void key_up_handler(const SDL_Event& event);
public:
    void input_event();
    bool is_quit_flag_set();
    //Mouse methods
    bool is_button_pressed(MouseButtonMask mouse_flag);
    bool is_button_just_pressed(MouseButtonMask mouse_flag);
    bool is_button_just_released(MouseButtonMask mouse_flag);
    Vector2DF get_absolute_position();
    Vector2DF get_relative_position();
    void get_absolute_position(float& absolute_x, float& absolute_y);
    void get_relative_position(float& relative_x, float& relative_y);
    //Keyboard methods
    bool is_key_pressed(SDL_Scancode key);
    bool is_key_just_pressed(SDL_Scancode key);
    bool is_key_just_released(SDL_Scancode key);
};