#include "cell.h"

Cell::Cell(int x, int y){
    this->x = x;
    this->y = y;
}

void Cell::get_coordinates(int& hover_x, int& hover_y){
    hover_x = this->x;
    hover_y = this->y;
}

Cell& Cell::operator=(const Cell& other){
    this->x = other.x;
    this->y = other.y;
    return *this;
}