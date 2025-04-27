#include "pipe.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>

Pipe::Pipe(SDL_Renderer* renderer, int x) {
    pipeTexture = IMG_LoadTexture(renderer, "assets/pipe.png");
    if (!pipeTexture) {
        std::cout << "Lỗi tải ảnh pipe: " << IMG_GetError() << std::endl;
    }

    topPipe.x = x;
    bottomPipe.x = x;
    topPipe.w = PIPE_WIDTH;
    bottomPipe.w = PIPE_WIDTH;

    // ✅ Luôn tạo khoảng trống ngẫu nhiên giữa ống trên và dưới
    int openingHeight = 100 + (rand() % 250);

    topPipe.y = 0; // ✅ Ống trên luôn chạm đỉnh màn hình
    topPipe.h = openingHeight; // ✅ Chiều cao ống trên thay đổi mỗi lần

    bottomPipe.y = openingHeight + PIPE_GAP; // ✅ Khoảng cách giữa hai ống luôn là 200
    bottomPipe.h = SCREEN_HEIGHT - (openingHeight + PIPE_GAP); // ✅ Ống dưới chạm đáy màn hình

    scored = false;
}

Pipe::~Pipe() {
    if (pipeTexture) {
        SDL_DestroyTexture(pipeTexture);
    }
}

void Pipe::update() {
    topPipe.x -= PIPE_SPEED;
    bottomPipe.x -= PIPE_SPEED;
}

void Pipe::render(SDL_Renderer* renderer) {
    if (pipeTexture) {
        SDL_RenderCopy(renderer, pipeTexture, nullptr, &topPipe);
        SDL_RenderCopy(renderer, pipeTexture, nullptr, &bottomPipe);
    }
}

bool Pipe::checkCollision(SDL_Rect birdRect) {
    int safeWidth = 20;  // ✅ Chim có thể chạm 15 pixels theo chiều rộng mà không chết
    int safeHeight = 30; // ✅ Chim có thể chạm 10 pixels theo chiều dài mà không chết

    SDL_Rect topSafeRect = { topPipe.x + safeWidth, topPipe.y, topPipe.w - safeWidth * 2, topPipe.h - safeHeight };
    SDL_Rect bottomSafeRect = { bottomPipe.x + safeWidth, bottomPipe.y + safeHeight, bottomPipe.w - safeWidth * 2, bottomPipe.h - safeHeight };
    return SDL_HasIntersection(&birdRect, &topPipe) || SDL_HasIntersection(&birdRect, &bottomPipe);
}
