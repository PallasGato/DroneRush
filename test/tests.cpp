#include <catch2/catch_all.hpp>
#include "geometry.h"

// Vector2DF overload operator+ test
TEST_CASE("Перегрузка оператора + для нулевых векторов", "[Vector2DF]") {
    Vector2DF result = Vector2DF{0.0f, 0.0f} + Vector2DF{0.0f, 0.0f};
    REQUIRE(result.x == Catch::Approx(0.0f));
    REQUIRE(result.y == Catch::Approx(0.0f));
}

TEST_CASE("Перегрузка оператора + {1.0, 2.0} + {3.0, 4.0} = {4.0, 6.0}", "[Vector2DF]") {
    Vector2DF result = Vector2DF{1.0f, 2.0f} + Vector2DF{3.0f, 4.0f};
    REQUIRE(result.x == Catch::Approx(4.0f));
    REQUIRE(result.y == Catch::Approx(6.0f));
}

TEST_CASE("Перегрузка оператора + {-1.0, -2.0} + {-3.0, -4.0} = {-4.0, -6.0}", "[Vector2DF]") {
    Vector2DF result = Vector2DF{-1.0f, -2.0f} + Vector2DF{-3.0f, -4.0f};
    REQUIRE(result.x == Catch::Approx(-4.0f));
    REQUIRE(result.y == Catch::Approx(-6.0f));
}