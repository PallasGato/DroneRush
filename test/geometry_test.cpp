#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "geometry.h"
//General Vector2DF tests
//Seem not so necessary

// Vector2DF overload operator+ test
TEST_CASE("Тест 1: Перегрузка оператора + для нулевых векторов", "[Vector2DF]") {
    Vector2DF result = Vector2DF{0.0f, 0.0f} + Vector2DF{0.0f, 0.0f};
    REQUIRE(result.x == Catch::Approx(0.0f));
    REQUIRE(result.y == Catch::Approx(0.0f));
}

TEST_CASE("Тест 2: Перегрузка оператора + {1.0, 2.0} + {3.0, 4.0} = {4.0, 6.0}", "[Vector2DF]") {
    Vector2DF result = Vector2DF{1.0f, 2.0f} + Vector2DF{3.0f, 4.0f};
    REQUIRE(result.x == Catch::Approx(4.0f));
    REQUIRE(result.y == Catch::Approx(6.0f));
}

TEST_CASE("Тест 3: Перегрузка оператора + {-1.0, -2.0} + {-3.0, -4.0} = {-4.0, -6.0}", "[Vector2DF]") {
    Vector2DF result = Vector2DF{-1.0f, -2.0f} + Vector2DF{-3.0f, -4.0f};
    REQUIRE(result.x == Catch::Approx(-4.0f));
    REQUIRE(result.y == Catch::Approx(-6.0f));
}

//Vector2DF overload operator== test
TEST_CASE("Тест 4: Перегрузка оператора == для векторов {1.0, 2.0} и {1.0, 2.0}", "[Vector2DF]") {
    Vector2DF vec1{1.0f, 2.0f};
    Vector2DF vec2{1.0f, 2.0f};
    REQUIRE(vec1.x == vec2.x);
    REQUIRE(vec1.y == vec2.y);
}

TEST_CASE("Тест 5: Перегрузка оператора == для векторов {1.0, 1.0} и {1.0, 2.0}", "[Vector2DF]") {
    Vector2DF vec1{1.0f, 1.0f};
    Vector2DF vec2{1.0f, 2.0f};
    REQUIRE(vec1.x == vec2.x);
    REQUIRE(vec1.y != vec2.y);
}

TEST_CASE("Тест 6: Перегрузка оператора == для векторов {2.0, 1.0} и {1.0, 1.0}", "[Vector2DF]") {
    Vector2DF vec1{2.0f, 1.0f};
    Vector2DF vec2{1.0f, 1.0f};
    REQUIRE(vec1.x != vec2.x);
    REQUIRE(vec1.y == vec2.y);
}

TEST_CASE("Тест 7: Перегрузка оператора == для векторов {2.0, 1.0} и {1.0, 2.0}", "[Vector2DF]") {
    Vector2DF vec1{2.0f, 1.0f};
    Vector2DF vec2{1.0f, 2.0f};
    REQUIRE(vec1.x != vec2.x);
    REQUIRE(vec1.y != vec2.y);
}

//Vector2DF overload operator+= test
TEST_CASE("Тест 8: Перегрузка оператора += для векторов {1.0, 2.0} и {3.0, 4.0}", "[Vector2DF]") {
    Vector2DF vec1{1.0f, 2.0f};
    Vector2DF vec2{3.0f, 4.0f};
    vec1 += vec2;
    REQUIRE(vec1.x == Catch::Approx(4.0f));
    REQUIRE(vec1.y == Catch::Approx(6.0f));
}  

//screen_to_world test
TEST_CASE("Тест 9: Функция screen_to_world для точки {1.0, 2.0} и позиции камеры {3.0, 4.0}", "[screen_to_world]") {
    Vector2DF point{1.0f, 2.0f};
    Vector2DF camera_position{3.0f, 4.0f};
    Vector2DF result = screen_to_world(point, camera_position);
    REQUIRE(result.x == Catch::Approx(4.0f));
    REQUIRE(result.y == Catch::Approx(6.0f));
}

TEST_CASE("Тест 10: Функция screen_to_world для точки {-1.0, -2.0} и позиции камеры {-3.0, -4.0}", "[screen_to_world]") {
    Vector2DF point{-1.0f, -2.0f};
    Vector2DF camera_position{-3.0f, -4.0f};
    Vector2DF result = screen_to_world(point, camera_position);
    REQUIRE(result.x == Catch::Approx(-4.0f));
    REQUIRE(result.y == Catch::Approx(-6.0f));
}

TEST_CASE("Тест 11: Функция screen_to_world для точки {0.0, 0.0} и позиции камеры {0.0, 0.0}", "[screen_to_world]") {
    Vector2DF point{0.0f, 0.0f};
    Vector2DF camera_position{0.0f, 0.0f};
    Vector2DF result = screen_to_world(point, camera_position);
    REQUIRE(result.x == Catch::Approx(0.0f));
    REQUIRE(result.y == Catch::Approx(0.0f));
}

TEST_CASE("Тест 12: Функция screen_to_world для точки {1.0, 2.0} и позиции камеры {-3.0, -3.0}", "[screen_to_world]") {
    Vector2DF point{1.0f, 2.0f};
    Vector2DF camera_position{-3.0f, -3.0f};
    Vector2DF result = screen_to_world(point, camera_position);
    REQUIRE(result.x == Catch::Approx(-2.0f));
    REQUIRE(result.y == Catch::Approx(-1.0f));
}