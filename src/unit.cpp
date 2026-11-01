#include "unit.h"
#include "grid.h"

Unit::Unit(){

}


void Unit::draw(SDL_Renderer& renderer, const Vector2DF& view_position){
    if (visible){
        //Drawing the unit as a simple rectangle for now
        Vector2DF screen_position = world_to_screen(world_position, view_position);
        SDL_FRect unit_rect = {screen_position.x - (size / 2), screen_position.y - (size /2), size, size};
        SDL_SetRenderDrawColor(&renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(&renderer, &unit_rect);
    }
}

void Unit::change_visibility(bool visibility){
    this->visible = visibility;
}

void Unit::set_position(Vector2DF position){
    this->world_position = position;
}

//Задание целевой позиции и 
void Unit::set_target_position(Vector2DF position, std::list<Unit*>& moving_units){
    target_position = position;
    moving_units.push_back(this);
}

bool Unit::is_selected() const {
    return this->selected;
}

void Unit::set_selection(bool selection){
    this->selected = selection;
}

//Метод перемещения юнита
//Метод возвращает true, если в текущей итерации юнит переместился
//Целевую ячейку
bool Unit::move(Grid& grid){
    //Вычсиление дистанции до целевой позиции (тупо гипотенуза)
    Vector2DF normalized_direction = normalized_delta(world_position, target_position);
    this->world_position += normalized_direction;
    surrounding_cells = grid.get_surroundings(target_position, size + bounding_circle_size);
    if (distance(world_position, target_position) < 1.0f){
        world_position = target_position;
        return true;
    }
    return false;
}

bool Unit::is_moving() const {
    return this->moving;
}

void Unit::set_moving(bool is_moving) {
    this->moving = is_moving;
}

void Unit::change_target_position(Vector2DF position){
    this->target_position = position;
}