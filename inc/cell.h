#pragma once


class Cell{
private:
    int x;
    int y;
public:
    Cell() : x(0), y(0) {}
    Cell(int x, int y);
    void get_coordinates(int& hover_x, int& hover_y);
    Cell& operator=(const Cell& other);
};