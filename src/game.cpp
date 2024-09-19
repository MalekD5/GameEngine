#include <SDL.h>
#include "game.h"


void Game::draw(const SDL_Rect& rect) const {
    SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

void Game::destroy() const {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer* Game::getRenderer() const {
    return renderer;
}

bool Game::isRunning() const {
    return running;
}

void Game::setRunning(const bool running) {
    this->running = running;
}

int Game::getWidth() const {
    return width;
}

int Game::getHeight() const {
    return height;
}


