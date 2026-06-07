#pragma once

#include <SDL3/SDL.h>
#include "geometry.h"

class GameObject{
protected:
    bool visible;
    Vector2DF position;
public:
    virtual ~GameObject();
    GameObject(){
        visible = true;
        position = {0, 0};
    }
    virtual void draw(SDL_Renderer& renderer, Vector2DF view_position) = 0;
    void change_visibility(bool visibility);
    
};