#include "game.h"
#include "unit.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

Game::Game() : window(nullptr), renderer(nullptr) {}

Game::~Game() {
    clean();
}

void Game::init() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow("Age of War", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Tạo các đơn vị lính
    units.push_back(Unit(100, 100, 100, 5));
    units.push_back(Unit(200, 200, 100, 5));
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            clean();
        }
    }
}

void Game::update() {
    // Cập nhật logic game (ví dụ: di chuyển các đơn vị)
    for (auto& unit : units) {
        unit.move(1, 0);  // Di chuyển tất cả lính sang phải
    }
}

void Game::render() {
    SDL_RenderClear(renderer);

    // Vẽ tất cả đơn vị lính
    for (auto& unit : units) {
        unit.render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
