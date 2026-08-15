cmake_minimum_required(VERSION 3.10)

project(DroneRush LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
find_package(fmt CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)

file(GLOB SOURCES "src/*.cpp")
file(GLOB TEST_SOURCES "test/*.cpp")
add_executable(main 
    ${SOURCES})

add_executable(tests
    ${TEST_SOURCES}
    src/cell.cpp
    src/grid.cpp
    src/game_scene.cpp
    src/scene.cpp
    src/camera.cpp
    src/input_handler.cpp
    src/geometry.cpp
    src/ui_object.cpp
    src/game_object.cpp
    src/terrain.cpp)

target_include_directories(
    main
    PRIVATE
    "${PROJECT_SOURCE_DIR}/inc"
)

target_include_directories(
    tests
    PRIVATE
    "${PROJECT_SOURCE_DIR}/inc"
)

target_link_libraries(
    main
    PRIVATE
    fmt::fmt
    SDL3::SDL3
)
target_link_libraries(
    tests
    PRIVATE
    Catch2::Catch2WithMain
    SDL3::SDL3
)

enable_testing()
add_test(NAME tests COMMAND tests)