#include "camera.h"

Camera::Camera(float x_pos, float y_pos){
    x = x_pos;
    y = y_pos;
}

Camera::Camera(){
    x = 0;
    y = 0;
}

Camera::move(float x_pos, float y_pos){
    x += x_pos;
    y += y_pos;
}