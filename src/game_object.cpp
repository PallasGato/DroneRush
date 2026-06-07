#include "game_object.h"

GameObject::~GameObject() = default;

void GameObject::change_visibility(bool visibility){
    visible = visibility;
}