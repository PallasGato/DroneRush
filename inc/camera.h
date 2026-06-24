#pragma once
#include <SDL3/SDL.h>
#include "geometry.h"
#include "game_object.h"

class Camera{
private:
    Vector2DF position;
public:
    Camera();
    Camera (float x_pos, float y_pos);
    void move(float x, float y);
    Vector2DF point_to_world(Vector2DF point);
    Vector2DF get_position();
};