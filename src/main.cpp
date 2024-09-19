#include <SDL.h>

void draw(SDL_Renderer* renderer, const SDL_Rect& rect) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255); // Set the background color to purple
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

int main (int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Blank Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    SDL_Rect rect;
    rect.x = 100;
    rect.y = 25;
    rect.w = 120;
    rect.h = 75;

    draw(renderer, rect);

    while (running) {
        // Close window with any input
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }


            if (event.type == SDL_MOUSEBUTTONDOWN) {
                rect.x += 1;
                draw(renderer, rect);
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
