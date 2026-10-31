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
    if (cell != nullptr && cell->is_valid()){
        cell->get_coordinates(this->x_cell, this->y_cell);
        this->world_position = cell->get_world_position();
        cell->set_occupant(this);
    }
}


//Просто задание целевой ячейки, без добавления юнита в пул перемещающихся юнитов
//Не уверен в целесообразности этого метода, но пусть будет
void Unit::set_target_cell(Cell* cell){
    this->target_cell = cell;
    if (cell != nullptr){
        cell->get_coordinates(this->target_x_cell, this->target_y_cell);
    }
}


//Задание целевой ячейки и добавление юнита в пул перемещающихся юнитов
void Unit::set_target_cell(Cell* cell, std::list<Unit*>& moving_units){
    this->target_cell = cell;
    if (cell != nullptr){
        cell->get_coordinates(this->target_x_cell, this->target_y_cell);
        moving_units.push_back(this);
    }
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
bool Unit::move(){
    //Честно говоря, нахуй проверка нужна. У нас же по сути ранее отсекается возможность 
    //того, что юнит может быть в пуле перемещающихся юнитов, если у него нет целевой валидной ячейки
    set_current_cell(target_cell);
    set_target_cell(nullptr);
    return true;
}