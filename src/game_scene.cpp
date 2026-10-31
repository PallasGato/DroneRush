#include "game_scene.h"

GameScene::GameScene(){ 
    auto grid_object = std::make_unique<Grid>(32, 32, 32);
    grid = grid_object.get();
    add_game_object(std::move(grid_object));

    auto highlight_object = std::make_unique<Rectangle>(0, 0, 32, 32, 
                                        Palette{127, 127, 127, 2});
    highlight = highlight_object.get();
    add_ui_object(std::move(highlight_object));

    auto test_unit = std::make_unique<Unit>();
    test_unit->set_current_cell(&grid->get_cell(16, 16));
    add_game_object(std::move(test_unit));

}


//Method to update current game state
void GameScene::update(InputHandler& input_handler){
    //Changing camera position with WASD keys
    if (input_handler.is_key_pressed(SDL_SCANCODE_W)){
        get_camera().move(0, -10);
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_S)){
        get_camera().move(0, 10);
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_A)){
        get_camera().move(-10, 0);
    }
    if (input_handler.is_key_pressed(SDL_SCANCODE_D)){
        get_camera().move(10, 0);
    }

    //Getting mouse position and converting it to world coordinates
    Vector2DF mouse_position = input_handler.get_absolute_position();
    Vector2DF mouse_to_world_position = get_camera().point_to_world(mouse_position);

    on_hover_cell = &grid->snap_to_grid(mouse_to_world_position);
    //Проверка на валидность полученной в текущем фрейме ячейки
    if (!on_hover_cell->is_valid()){
        on_hover_cell = last_valid_cell;
    }
    last_valid_cell = on_hover_cell;
    Vector2DF hover_position = on_hover_cell->get_world_position();
    highlight->set_position(world_to_screen(hover_position, get_camera().get_position()));

    //Проверка на выделение юнита по ЛКМ
    unit_selection(input_handler, *on_hover_cell);
    //Проверка на задание целевой ячейки для юнита по ПКМ
    cell_targeting(input_handler, *on_hover_cell);

    //Перемещение всех юнитов, которые находятся в пуле перемещающихся юнитов
    move_units();
    //Returning from the function (seems obvious to comment)
    return;
}

GameScene::~GameScene() = default;

//Приватные методы (подписывайтесь на мой онлифанс, там будет больше приватных методов)

//Метод для выделения юнита по ЛКМ
void GameScene::unit_selection(InputHandler& input_handler, Cell& cell){
    Unit* occupant = cell.get_occupant();
    //Для выполнения выделения юнита по клику мыши необходимо, чтобы:
    //1. Была нажата левая кнопка мыши
    //2. Ячейка, на которой находится курсор мыши, была валидной
    //3. В ячейке, на которой находится курсор мыши, находился юнит
    //4. Юнит не был уже выделен
    if (input_handler.is_button_just_pressed(LEFT_MOUSE_BUTTON)
    && cell.is_valid() && (occupant != nullptr)
    && !occupant->is_selected())
    {
        //Задание юнита как выделенного
        occupant->set_selection(true);
        //Добавление юнита в пул выделенных юнитов
        selected_units.push_back(cell.get_occupant());
    }
}

//Метод для задания целевой ячейки для юнита по ПКМ
void GameScene::cell_targeting(InputHandler& input_handler, Cell& cell){
    //Надо определить, есть ли юниты, но для начала проверим, что ПКМ была нажата
    if (input_handler.is_button_just_pressed(RIGHT_MOUSE_BUTTON) 
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
void GameScene::move_units(){
    for (Unit* unit : moving_units){
        bool unit_reached_destination = unit->move();
        if (unit_reached_destination){
            //Удаление юнита из пула перемещающихся юнитов
            moving_units.remove(unit);
            //Выход из функции если больше нет юнитов в пуле перемещающихся юнитов
            if (moving_units.empty()) return;
        }
    }
}