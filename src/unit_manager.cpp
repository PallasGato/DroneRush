#include "unit_manager.h"

UnitManager::UnitManager(InputHandler& input_handler){
    this->input_handler = &input_handler;
}

UnitManager::~UnitManager() = default;

//Метод для выделения юнита по ЛКМ
void UnitManager::unit_selection(Cell& cell){
    return;
}

//Метод для задания целевой ячейки для юнита по ПКМ
void UnitManager::unit_targeting(Cell& cell, Vector2DF mouse_world_position){
    if (input_handler->is_button_just_pressed(RIGHT_MOUSE_BUTTON) &&
        grid->snap_to_grid(mouse_world_position).is_valid()){
        for (Unit* unit : selected_units){
            if (!unit->is_moving()){
                unit->set_moving(true);
                unit->set_target_position(mouse_world_position, moving_units);
            }
            else {
                unit->change_target_position(mouse_world_position);
            }
        }
    }
}


//Метод перемещения юнитов в пуле юнитов
//Пока тупо телепортация
void UnitManager::move_units(float delta_time){
    //Написала нейронка. Но это решает косяки с сегфолтом
    //Для того, чтобы удаляемый юнит не переёбывал весь список
    for (auto it = moving_units.begin(); it != moving_units.end();){
        bool moved = (*it)->move(*grid);
        if (moved){
            //Дошёл до целевой позиции, удаляем из списка
            //Убираем флаг движения
            (*it)->set_moving(false);
            it = moving_units.erase(it);
        } else {
            ++it;
        }
    }
}

void UnitManager::reset_selected_units(){
    if (input_handler->is_key_just_pressed(SDL_SCANCODE_ESCAPE)){
        for (Unit* unit : selected_units){
            unit->set_selection(false);
        }
        selected_units.clear();
    }
}

void UnitManager::process_units(Cell& cell, float delta_time, Vector2DF mouse_world_position){
    //Метод для выделения юнита по ЛКМ
    unit_selection(cell);
    //Метод для задания целевой ячейки для ПКМ
    unit_targeting(cell, mouse_world_position);
    //Метод для отмены выделения юнитов по ESC
    reset_selected_units();
    //Обработка передвижения юнитов
    move_units(delta_time);
}

void UnitManager::set_grid(Grid* grid){
    this->grid = grid;
}

void UnitManager::add_selected_unit(Unit* unit){
    selected_units.push_back(unit);
}