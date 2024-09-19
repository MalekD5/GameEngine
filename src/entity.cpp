#include "entity.h"

Entity::Entity(const int id, const int x, const int y, const int w, const int h) {
    this->id = id;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void EntityRect::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &this->type);

    SDL_RenderPresent(renderer);
}

void EntityRect::update(SDL_Renderer* renderer, const int stepX) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 180, 255);
    SDL_RenderClear(renderer);

    this->type.x += stepX;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &this->type);

    SDL_RenderPresent(renderer);
}


EntityRect::EntityRect(const int id, const int x, const int y, const int w, const int h): Entity(id, x, y, w, h) {
    this->type = {
        x, y, w, h
    };
}

SDL_Rect EntityRect::getType() const {
    return this->type;
}



