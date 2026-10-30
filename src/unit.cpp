#include "unit.h"

Unit::Unit(){

}


void Unit::draw(SDL_Renderer& renderer, const Vector2DF& view_position){
    if (visible){
        //Drawing the unit as a simple rectangle for now
        Vector2DF screen_position = world_to_screen(world_position, view_position);
        SDL_FRect unit_rect = {screen_position.x, screen_position.y, 32, 32};
        SDL_SetRenderDrawColor(&renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(&renderer, &unit_rect);
    }
}

void Unit::change_visibility(bool visibility){
    this->visible = visibility;
}

void Unit::set_current_cell(Cell* cell){
    this->current_cell = cell;
    if (cell != nullptr){
        cell->get_coordinates(this->x_cell, this->y_cell);
        this->world_position = cell->get_world_position();
    }
}

void Unit::set_target_cell(Cell* cell){
    this->target_cell = cell;
    if (cell != nullptr){
        cell->get_coordinates(this->target_x_cell, this->target_y_cell);
    }
}