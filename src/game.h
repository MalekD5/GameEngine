#pragma once
#include <SDL.h>

#ifndef GAME_H
#define GAME_H

#endif //GAME_H

struct Game {
    Game() {
        SDL_Init(SDL_INIT_VIDEO);

        window = SDL_CreateWindow("Blank Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            return;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if (renderer == nullptr) {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }

        running = true;
    }

    void draw(const SDL_Rect& rect) const;
    void destroy() const;
    bool isRunning() const;
    void setRunning(const bool running);
    int getHeight() const;
    int getWidth() const;

    SDL_Renderer* getRenderer() const;

    private:
        SDL_Renderer* renderer;
        SDL_Window* window;
        bool running = false;
        int width = 800;
        int height = 600;

};
