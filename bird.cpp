#include "bird.h"

Bird::Bird(SDL_Renderer* renderer) {
    texture = IMG_LoadTexture(renderer, "assets/bird.png");
    if (!texture) {
        std::cout << "Failed to load bird texture: " << IMG_GetError() << std::endl;
    }
    rect = { 200, SCREEN_HEIGHT / 2, BIRD_WIDTH, BIRD_HEIGHT };
    velocity = 0.0f;
}

void Bird::update() {
    velocity += GRAVITY; 
    rect.y += static_cast<int>(velocity);
}

void Bird::flap() {
    velocity = FLAP_STRENGTH;
}
void Bird::reset() {
    rect.x = 50; 
    rect.y = SCREEN_HEIGHT / 2;
    velocity = 0;
}
void Bird::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

Bird::~Bird() {
    SDL_DestroyTexture(texture);
}
