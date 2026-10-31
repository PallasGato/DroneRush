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
    if (cell != nullptr && cell->is_valid()){
        if (this->current_cell != nullptr){
            this->current_cell->set_occupant(nullptr);
        }
        this->current_cell = cell;
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
        if (cell->get_occupant() != nullptr){
            //Если в целевой ячейке уже есть юнит, то не будем туда перемещаться
            return;
        }
        cell->get_coordinates(this->target_x_cell, this->target_y_cell);
        if (!moving){
            moving = true;
            moving_units.push_back(this);
        }
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

    if (target_cell == nullptr || !target_cell->is_valid()){
        #ifdef DEBUG_MODE
        SDL_Log("Unit has no valid target cell. Cannot move.");
        #endif

        return false;
    }

    //Проверка на то, что другой юнит не занял целевую ячейку.
    //В этом случае остаёмся на месте
    if (target_cell->get_occupant() != nullptr){
        moving = false;
        return true;
    }
    //Стрелок дошёл до исполнителя желаний. Его цель здесь. Вознаграждён будет только один
    moving = false;
    set_current_cell(target_cell);
    set_target_cell(nullptr);
    return true;
}