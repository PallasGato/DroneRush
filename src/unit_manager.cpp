#include "unit_manager.h"

UnitManager::UnitManager(InputHandler& input_handler){
    this->input_handler = &input_handler;
}

UnitManager::~UnitManager() = default;

//Метод для выделения юнита по ЛКМ
void UnitManager::unit_selection(Cell& cell){
    Unit* occupant = cell.get_occupant();
    //Для выполнения выделения юнита по клику мыши необходимо, чтобы:
    //1. Была нажата левая кнопка мыши
    //2. Ячейка, на которой находится курсор мыши, была валидной
    //3. В ячейке, на которой находится курсор мыши, находился юнит
    //4. Юнит не был уже выделен
    if (input_handler->is_button_just_pressed(LEFT_MOUSE_BUTTON)
    && cell.is_valid() && (occupant != nullptr)
    && !occupant->is_selected())
    {
        //Задание юнита как выделенного
        occupant->set_selection(true);
        //Добавление юнита в пул выделенных юнитов
        selected_units.push_back(cell.get_occupant());
    }
    //Если юнита нет на ячейке, то сбрасываются все юниты
    if (input_handler->is_button_just_pressed(LEFT_MOUSE_BUTTON)
    && cell.is_valid() && (occupant == nullptr))
    {
        for (Unit* unit : selected_units){
            unit->set_selection(false);
        }
        selected_units.clear();
    }
}

//Метод для задания целевой ячейки для юнита по ПКМ
void UnitManager::cell_targeting(Cell& cell){
    //Надо определить, есть ли юниты, но для начала проверим, что ПКМ была нажата
    if (input_handler->is_button_just_pressed(RIGHT_MOUSE_BUTTON) 
    && cell.is_valid())
    {
        //Не буду инвертировать логику и возвращаться из функции
        //Потом поменять не проблема, когда я ещё буду делать логику постройки зданий
        //Просто смотрим, есть ли выделенные юниты
        if (!selected_units.empty()){
            //Если есть, то задаём им целевую ячейку
            for (Unit* unit : selected_units){
                unit->set_target_cell(&cell, moving_units);
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
    if ((*it)->move()){
        //Если юнит дошёл до ячейки, либо движение заблокировано другим юнитом, то удаляем его из пула перемещающихся юнитов
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

void UnitManager::process_units(Cell& cell, float delta_time){
    //Метод для выделения юнита по ЛКМ
    unit_selection(cell);
    //Метод для задания целевой ячейки для ПКМ
    cell_targeting(cell);
    //Метод для отмены выделения юнитов по ESC
    reset_selected_units();
    //Обработка передвижения юнитов
    move_units(delta_time);
}