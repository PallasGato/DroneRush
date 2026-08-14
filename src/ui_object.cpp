#include "ui_object.h"

UIobject::UIobject(){
    visible = true;
}

void UIobject::change_visibility(bool visible){
    visible = visible;
}

bool UIobject::is_visible(){
    return visible;
}

Rectangle::Rectangle(float x, float y, float width, float height, Palette palette){
    rectangle = {x, y, width, height};
    color = palette;
}

void Rectangle::set_position(float x, float y){
    rectangle.x = x;
    rectangle.y = y;
}

void Rectangle::set_position(Vector2DF position){
    rectangle.x = position.x;
    rectangle.y = position.y;
}

void Rectangle::draw(SDL_Renderer& renderer){
    if (is_visible()){
        SDL_SetRenderDrawColor(&renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(&renderer, &rectangle);
    }
}
