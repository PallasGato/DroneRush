#pragma once
#include <SDL3/SDL.h>
#include "palette.h"
#include "geometry.h"

class UIobject{
private:
    bool visible;
public:
    UIobject();
    void change_visibility(bool visibility);
    bool is_visible();
    virtual void draw(SDL_Renderer& renderer) = 0;
};

class Overlay: public UIobject{
private:

public:
    void set_position();
    void translate();
};

class Rectangle: public Overlay{
private:
    SDL_FRect rectangle;
    int x;
    int y;
    int width;
    int height;
    Palette color;
public:
    Rectangle(float x, float y, float width, float height, Palette palette);
    void set_position(float x, float y);
    void set_position(Vector2DF position);
    void draw(SDL_Renderer& renderer);
};