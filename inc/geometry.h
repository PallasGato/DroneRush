#pragma once

struct  Vector2DF{
    float x;
    float y;

    Vector2DF& operator+=(const Vector2DF& other){
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
};

