//
// Created by Steve M on 9/20/2024.
//

#ifndef ENTITY_H
#define ENTITY_H
#include <SDL_rect.h>
#include <SDL_render.h>

#endif //ENTITY_H


struct Entity {
    virtual ~Entity() = default;

    int id, x, y, w, h;

    Entity(int id, int x, int y, int w, int h);

    virtual void draw(SDL_Renderer* renderer) {}

    virtual void update(SDL_Renderer* renderer, int stepX) {}

};

struct EntityRect final: Entity {
    EntityRect(int id, int x, int y, int w, int h);

    SDL_Rect getType() const;

    void draw(SDL_Renderer* renderer) override;

    void update(SDL_Renderer* renderer, int stepX) override;

private:
    SDL_Rect type{};

};