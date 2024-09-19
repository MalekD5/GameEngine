#include <SDL.h>

#include "entity.h"
#include "game.h"

int main(int argc, char* args[]) {
    Game game;

    SDL_Renderer* renderer = game.getRenderer();

    SDL_Event event;

    EntityRect rect = {
        1,
        100,
        25,
        120,
        75
    };

    // Draw the initial scene
    game.draw(rect.getType());

    bool isMouseButtonDown = false;

    while (game.isRunning()) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game.setRunning(false);
                break;
            }

            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                isMouseButtonDown = true;
            }

            // Check if the left mouse button is released
            if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
                isMouseButtonDown = false;
            }
        }

        if (isMouseButtonDown) {
            if (rect.getType().x < game.getWidth() - rect.getType().w) {
                rect.update(renderer, 10);
            }
        }

        SDL_Delay(16);
    }

    game.destroy();
    return 0;
}
