#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "grid.h"
TEST_CASE("Тест 1: Привязка координат к сетке для позиции (0, 0) на сетке с шагом 32", "[Grid]") {
    Grid grid(10, 10, 32.0f);
    Vector2DF position{0.0f, 0.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == 0 );
    REQUIRE(y == 0);
}

TEST_CASE("Тест 2: Привязка координат к сетке для позиции (32, 32) на сетке с шагом 32", "[Grid]") {
    Grid grid(10, 10, 32.0f);
    Vector2DF position{32.0f, 32.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == 1);
    REQUIRE(y == 1);
}

TEST_CASE("Тест 3: Привязка координат к сетке для позиции (33, 33) на сетке с шагом 32", "[Grid]") {
    Grid grid(10, 10, 32.0f);
    Vector2DF position{33.0f, 33.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == 1);
    REQUIRE(y == 1);
}

TEST_CASE("Тест 4: Привязка координат к сетке для позиции (33, 32) на сетке с шагом 32", "[Grid]") {
    Grid grid(10, 10, 32.0f);
    Vector2DF position{33.0f, 32.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == 1);
    REQUIRE(y == 1);
}

TEST_CASE("Тест 5: Привязка координат к сетке для позиции (-10, -10) на сетке с шагом 32", "[Grid]") {
    Grid grid(10, 10, 32.0f);
    Vector2DF position{-10.0f, -10.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(!cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == -1);
    REQUIRE(y == -1);
}

TEST_CASE("Тест 6: Привязка координат к сетке для позиции (-33, -33) на сетке с шагом 32", "[Grid]") {
    Grid grid(10, 10, 32.0f);
    Vector2DF position{-33.0f, -33.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(!cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == -1);
    REQUIRE(y == -1);
}

TEST_CASE("Тест 7: Привязка координат к сетке для позиции (65, 0) на сетке с шагом 32", "[Grid]") {
    Grid grid(2, 2, 32.0f);
    Vector2DF position{65.0f, 0.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(!cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == -1);
    REQUIRE(y == -1);
}

TEST_CASE("Тест 8: Привязка координат к сетке для позиции (65, 0) на сетке с шагом 32", "[Grid]") {
    Grid grid(2, 2, 32.0f);
    Vector2DF position{65.0f, 0.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(!cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == -1);
    REQUIRE(y == -1);
}

TEST_CASE("Тест 9: Привязка координат к сетке для позиции (-0.1, -0.5) на сетке с шагом 32", "[Grid]") {
    Grid grid(2, 2, 32.0f);
    Vector2DF position{-0.1f, -0.5f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == 0);
    REQUIRE(y == 0);
}

TEST_CASE("Тест 10: Привязка координат к сетке для позиции (0, -0.5) на сетке с шагом 32", "[Grid]") {
    Grid grid(2, 2, 32.0f);
    Vector2DF position{0.0f, -0.5f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == 0);
    REQUIRE(y == 0);
}

TEST_CASE("Тест 11: Привязка координат к сетке для позиции (-1.0, 0) на сетке с шагом 32", "[Grid]") {
    Grid grid(2, 2, 32.0f);
    Vector2DF position{-1.0f, 0.0f};
    Cell& cell = grid.snap_to_grid(position);
    REQUIRE(!cell.is_valid());
    int x, y;
    cell.get_coordinates(x, y);
    REQUIRE(x == -1);
    REQUIRE(y == -1);
}