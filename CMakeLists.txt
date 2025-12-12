cmake_minimum_required(VERSION 3.0)
project(FallingSand)

find_package(raylib CONFIG REQUIRED)

option(BUILD_COLOR_TEST "Build the color testing tool" OFF)

add_executable(FallingSand
    src/falling_sand.c
    src/colorManager.c
)
target_link_libraries(FallingSand PRIVATE raylib)

if (BUILD_COLOR_TEST)
    add_executable(ColorTest
        test/color_test.c
        src/colorManager.c
    )
    target_link_libraries(ColorTest PRIVATE raylib)
endif()