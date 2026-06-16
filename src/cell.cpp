#include "cell.h"

Cell::Cell(int x, int y){
    this.x = x;
    this.y = y;
}

void Cell::get_coordinates(int& x, int& y){
    x = this.x;
    y = this.y;
}