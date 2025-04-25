#ifndef BIRD_H
#define BIRD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "main.h"

const int BIRD_WIDTH = 50;
const int BIRD_HEIGHT = 50;
const float GRAVITY = 0.5f;
const float FLAP_STRENGTH = -8.0f;

class Bird {
public:
    SDL_Rect rect;
    float velocity;
    SDL_Texture* texture;

    Bird(SDL_Renderer* renderer);
    void update();
    void flap();
    void render(SDL_Renderer* renderer);
    void reset();
    ~Bird();
};

#endif
