#include "game.h"
#include <SDL2/SDL_image.h>
#include <cstdlib>

Game::Game() {
    window = nullptr;
    renderer = nullptr;
    background = nullptr;
    bird = nullptr;
    running = true;
}

Game::~Game() {
    clean();
}

void Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Initialization Error: " << SDL_GetError() << std::endl;
        running = false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_image Initialization Error: " << IMG_GetError() << std::endl;
        running = false;
    }

    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    background = IMG_LoadTexture(renderer, "assets/background.png");
    bird = new Bird(renderer);

    // ✅ Khởi tạo ống nước với khoảng cách đều nhau và vị trí ngẫu nhiên
    for (int i = 0; i < 6; i++) {
        int randomOffset = rand() % 100; // ✅ Thêm độ lệch ngẫu nhiên để tránh lặp lại thử thách
        pipes.push_back(new Pipe(renderer, SCREEN_WIDTH + i * 250 + randomOffset));
    }
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) running = false;
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
            bird->flap();
        }
    }
}

void Game::update() {
    bird->update();

    for (size_t i = 0; i < pipes.size(); i++) {
        pipes[i]->update();

        // ✅ Nếu ống nước ra khỏi màn hình, xóa ống cũ và thêm ống mới với vị trí ngẫu nhiên
        if (pipes[i]->topPipe.x + pipes[i]->topPipe.w < 0) {
            delete pipes[i];
            pipes.erase(pipes.begin() + i);

            int newX = SCREEN_WIDTH + 250 + (rand() % 100); // ✅ Đảm bảo vị trí xuất hiện không bị lặp lại
            pipes.push_back(new Pipe(renderer, newX));
        }
    }

    // ✅ Luôn có đủ số lượng ống nước trong trò chơi
    while (pipes.size() < 6) {
        int lastPipeX = pipes.back()->topPipe.x;
        pipes.push_back(new Pipe(renderer, lastPipeX + 250));
    }

    if (checkCollision()) {
        running = false;
    }

    if (bird->rect.y + bird->rect.h >= SCREEN_HEIGHT || bird->rect.y <= 0) {
        running = false;
    }
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    bird->render(renderer);

    for (auto pipe : pipes) {
        pipe->render(renderer);
    }

    SDL_RenderPresent(renderer);
}

bool Game::checkCollision() {
    for (auto pipe : pipes) {
        if (pipe->checkCollision(bird->rect)) {
            return true;
        }
    }
    return false;
}

void Game::clean() {
    SDL_DestroyTexture(background);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete bird;
    for (auto pipe : pipes) {
        delete pipe;
    }
    IMG_Quit();
    SDL_Quit();
}
