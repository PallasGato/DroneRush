#pragma once

#include <vector>
struct  Vector2DF{
    float x;
    float y;

    Vector2DF& operator+=(const Vector2DF& other){
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Vector2DF& operator+(const Vector2DF& other){
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
};

template <typename T> 
void world_to_screen(std::vector<T>& points, const T& view_position){
    for (auto& point : points) {
        point.x -= view_position.x;
        point.y -= view_position.y;
    }
}

template <typename T, typename U> 
void world_to_screen(std::vector<T>& points, const U& view_position){
    for (auto& point : points) {
        point.x -= view_position.x;
        point.y -= view_position.y;
    }
}

Vector2DF screen_to_world(const Vector2DF& point, const Vector2DF& world_position);