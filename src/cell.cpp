#include "cell.h"


Cell::Cell(){
    this->x = 0;
    this->y = 0;
}

Cell::Cell(int x, int y){
    this->x = x;
    this->y = y;
}

void Cell::get_coordinates(int& hover_x, int& hover_y){
    hover_x = this->x;
    hover_y = this->y;
}

//Метод для установки мировых координат ячейки
void Cell::set_world_position(const Vector2DF& position){
    this->world_position = position;
}

//Перегрузка оператора присваивания для класса Cell
Cell& Cell::operator=(const Cell& other){
    this->x = other.x;
    this->y = other.y;
    this->world_position = other.world_position;
    return *this;
}