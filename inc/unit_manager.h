#pragma once

#include <list>
#include <SDL3/SDL.h>
#include "unit.h"
#include "grid.h"
#include "input_handler.h"

class UnitManager {
private:
    //Пул выделенных юнитов
    std::list<Unit*> selected_units;
    //Пул юнитов, которые должны двигаться
    std::list<Unit*> moving_units;

    //Хэндлер ввода для дальнейшей проверки нажимаемых клавиш
    InputHandler* input_handler;

    //Кто знает, может однажды клавиши будут маппиться по настройкам, а не хардкодиться
    //Метод для выделения юнита по ЛКМ
    void unit_selection(Cell& cell);
    //Метод для задания целевой ячейки для ПКМ
    void cell_targeting(Cell& cell);
    //Метод для отмены выделения юнитов по ESC
    void reset_selected_units();
    //Обработка передвижения юнитов
    void move_units(float delta_time);
public:
    //Конструктор и деструктор
    UnitManager(InputHandler& input_handler);
    ~UnitManager();

    void process_units(Cell& cell, float delta_time);


};