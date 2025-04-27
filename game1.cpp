#include "game.h"
#include "bird.h"
#include <SDL2/SDL_image.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <SDL2/SDL_mixer.h>
#include <fstream>
Game::Game() {
    window = nullptr;
    renderer = nullptr;
    background = nullptr;
    bird = nullptr;
    running = true;
}

Game::~Game() {
    gameOver = false;
    clean();
}

void Game::init() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    

    window = SDL_CreateWindow("Age Of War", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    std::ifstream file("assets/music.wav");
    if (!file) {
        std::cout << "Lỗi: File nhạc không tồn tại hoặc sai đường dẫn!" << std::endl;
    }
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048); // ✅ Khởi động SDL_Mixer
    gameMusic = Mix_LoadMUS("assets/music.wav");
    if (!gameMusic) {
        std::cout << "Lỗi tải nhạc nền: " << Mix_GetError() << std::endl;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cout << "Lỗi: Không thể mở audio! " << Mix_GetError() << std::endl;
    }
    gameOver = false; // ✅ Trò chơi bắt đầu, chưa Game Over
    if (renderer == nullptr) {
        std::cout << "SDL_CreateRenderer lỗi: " << SDL_GetError() << std::endl;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Initialization Error: " << SDL_GetError() << std::endl;
        running = false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_image Initialization Error: " << IMG_GetError() << std::endl;
        running = false;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "SDL_Image không khởi động đúng!" << std::endl;
        exit(1);
    }
    
    background = IMG_LoadTexture(renderer, "assets/background.png");
    bird = new Bird(renderer);

    // ✅ Khởi tạo ống nước với khoảng cách đều nhau và vị trí ngẫu nhiên
    for (int i = 0; i < 5; i++) {
        int randomOffset = rand() % 130 + 30; // ✅ Thêm độ lệch ngẫu nhiên để tránh lặp lại thử thách
        pipes.push_back(new Pipe(renderer, SCREEN_WIDTH + i * 250 + randomOffset));
    }
    score = 0; // ✅ Điểm số bắt đầu từ 0

    // ✅ Tải ảnh font vào bộ nhớ
    fontTexture = IMG_LoadTexture(renderer, "assets/font.png");
    if (!fontTexture) {
        std::cout << "Lỗi tải ảnh font: " << IMG_GetError() << std::endl;
    }
    if (gameMusic != nullptr) {
        Mix_PlayMusic(gameMusic, -1); // ✅ Phát nhạc nền lặp vô hạn
    }

}


void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT && !gameOver) {
            
            running = false;
        }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
                bird->flap();
            }
        
    }
}

void Game::update(){ 
    if (gameOver) return;
    bird->update();


    for (size_t i = 0; i < pipes.size(); i++) {
        pipes[i]->update();
        // ✅ Kiểm tra nếu chim đã đi qua ống nước chưa, nếu có thì cộng điểm
        if (!pipes[i]->scored && pipes[i]->topPipe.x + pipes[i]->topPipe.w < bird->rect.x) {
            score++; // ✅ Cộng điểm khi chim vượt qua ống
            pipes[i]->scored = true; // ✅ Đánh dấu ống này đã được tính điểm
        }

        // ✅ Nếu ống nước ra khỏi màn hình, xóa ống cũ và thêm ống mới với vị trí ngẫu nhiên
        if (pipes[i]->topPipe.x + pipes[i]->topPipe.w < 0) {
            delete pipes[i];
            pipes.erase(pipes.begin() + i);

            int newX = SCREEN_WIDTH + 250 + (rand() % 100); // ✅ Đảm bảo vị trí xuất hiện không bị lặp lại
            pipes.push_back(new Pipe(renderer, newX));
        }
    }

    // ✅ Luôn có đủ số lượng ống nước trong trò chơi
    while (pipes.size() < 5) {
        int lastPipeX = pipes.back()->topPipe.x;
        pipes.push_back(new Pipe(renderer, lastPipeX + 250));
    }

    if (checkCollision()) {
        running = false;
    }

    

    if (bird->rect.y + bird->rect.h >= SCREEN_HEIGHT || bird->rect.y <= 0) {
        running = false;
    }
    if (checkCollision() || bird->rect.y + bird->rect.h >= SCREEN_HEIGHT || bird->rect.y <= 0) {
        gameOver = true; // ✅ Khi chim va chạm, trò chơi kết thúc
    }


}

void Game::render() {
    if (!renderer) return; // ✅ Tránh lỗi khi renderer chưa được khởi tạo
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    SDL_RenderCopy(renderer, birdTexture, nullptr, &bird->rect);
    bird->render(renderer);

    for (auto pipe : pipes) {
        pipe->render(renderer);
    }

    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, nullptr, nullptr);
    bird->render(renderer);

    for (auto pipe : pipes) {
        pipe->render(renderer);
    }

    
    // ✅ Hiển thị điểm số từ ảnh font
    std::string scoreString = std::to_string(score);
    int xOffset = SCREEN_WIDTH / 2 - (scoreString.length() * 20);

    for (char digit : scoreString) {
        int num = digit - '0'; // ✅ Chuyển số từ ký tự sang số nguyên
        SDL_Rect srcRect = { num * 40, 0, 40, 40 }; // ✅ Xác định vị trí số trong `font.png`
        SDL_Rect destRect = { xOffset, 20, 40, 40 }; // ✅ Vị trí hiển thị trên màn hình
        SDL_RenderCopy(renderer, fontTexture, &srcRect, &destRect);
        xOffset += 10;
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
    
    SDL_DestroyTexture(fontTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(background);
    SDL_DestroyWindow(window);
    delete bird;
    for (auto pipe : pipes) {
        delete pipe;
    }
    IMG_Quit();
    SDL_Quit();
    Mix_FreeMusic(gameMusic);
    Mix_CloseAudio();
}

