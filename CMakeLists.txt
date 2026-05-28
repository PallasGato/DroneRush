cmake_minimum_required(VERSION 3.10)

project(DroneRush LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
find_package(fmt CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)

file(GLOB SOURCES "src/*.cpp")
add_executable(main 
    ${SOURCES})

target_include_directories(
    main
    PRIVATE
    "${PROJECT_SOURCE_DIR}/inc"
)

target_link_libraries(
    main
    PRIVATE
    fmt::fmt
    SDL3::SDL3
)