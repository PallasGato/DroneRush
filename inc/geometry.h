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
    Vector2DF operator+(const Vector2DF& other) const{
        return {x + other.x, y + other.y};
    }
    bool operator==(const Vector2DF& other) const{
        return (x == other.x && y == other.y);
    }
};

//Шаблон для перевода вектора из точек из мировых координат в экранные
//Используется для однотипных типов данных
template <typename T> 
void world_to_screen(std::vector<T>& points, const T& view_position){
    for (auto& point : points) {
        point.x -= view_position.x;
        point.y -= view_position.y;
    }
}

//Шаблон для перевода вектора из точек из мировых координат в экранные
//Используется для разных типов данных
template <typename T, typename U> 
void world_to_screen(std::vector<T>& points, const U& view_position){
    for (auto& point : points) {
        point.x -= view_position.x;
        point.y -= view_position.y;
    }
}

//Шаблон для перевода вектора из точек из мировых координат в экранные
//Используется для типов данных, которые не являются векторами или массивами
template <typename T>
T world_to_screen(const T& point, const T& view_position){
    T screen_point;
    screen_point.x = point.x - view_position.x;
    screen_point.y = point.y - view_position.y;
    return screen_point;
}

Vector2DF screen_to_world(const Vector2DF& point, const Vector2DF& world_position);
