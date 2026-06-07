#pragma once

#include <SDL3/SDL.h>

class GameObject{
protected:
    bool visible;
public:
    virtual ~GameObject();
    virtual void draw(SDL_Renderer& renderer) = 0;
    void change_visibility(bool visibility){
        visible = visibility;
    }
    
};