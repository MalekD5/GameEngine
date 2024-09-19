cmake_minimum_required(VERSION 3.29)

project(GameEngine)

set(CMAKE_CXX_STANDARD 14)

# Must set the path to the main.cpp, for example: scripts/main.cpp if it is inside a folder
add_executable(${PROJECT_NAME} src/main.cpp
        src/game.cpp
        src/game.h)

# --- SDL2 SETUP ---
find_package(SDL2 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)