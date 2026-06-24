#pragma once

class Cell{
private:
    int x;
    int y;
public:
    Cell();
    Cell(int x, int y);
    void get_coordinates(int& hover_x, int& hover_y);
    Cell& operator=(const Cell& other);
};