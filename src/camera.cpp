#include "camera.h"

Camera::Camera(float x_pos, float y_pos){
    position.x = x_pos;
    position.y = y_pos;
}

Camera::Camera(){
    position.x = 0;
    position.y = 0;
}

void Camera::move(float x_pos, float y_pos){
    position.x += x_pos;
    position.y += y_pos;
}

Vector2DF Camera::point_to_world(Vector2DF point){
    return screen_to_world(point, position);
}

Vector2DF Camera::get_position(){
    return position;
}