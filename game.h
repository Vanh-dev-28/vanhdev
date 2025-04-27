#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <vector>
#include "pipe.h"
#include "bird.h"
#include <SDL2/SDL_mixer.h>

class Game {
public:
    Game();
    ~Game();
    int score;
    SDL_Texture* fontTexture;
    SDL_Renderer* renderer;
    SDL_Texture* birdTexture ;
    Mix_Music* gameMusic = nullptr;
    SDL_Rect birdRect;

    void init();
    void handleEvents();
    void update();
    void render();
    void clean();
    void resetGame();
    
    
    bool running; //  Biến kiểm soát trạng thái game
    bool gameOver; // ✅ Kiểm tra trò chơi đã kết thúc chưa
    std::vector<Pipe*> pipes; // Danh sách ống nước trong trò chơi

private:
    SDL_Window* window;
   
    SDL_Texture* background;
    Bird* bird;

    bool checkCollision();
};
#endif
