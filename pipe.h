#ifndef PIPE_H
#define PIPE_H

#include <SDL2/SDL.h>
#include <iostream> 
#include "main.h"
class Pipe {
public:
    Pipe(SDL_Renderer* renderer, int x);
    ~Pipe(); 

    void update();
    void render(SDL_Renderer* renderer);
    void reset(int newX); 
    bool checkCollision(SDL_Rect birdRect); 
    SDL_Rect topPipe;
    SDL_Rect bottomPipe; // Fix lỗi chưa khai báo bottomPipe
    bool scored; // Kiểm tra nếu chim đã bay qua ống nước

private:
    SDL_Texture* pipeTexture;

    //  Các hằng số xác định kích thước, khoảng cách và tốc độ của ống nước
    static constexpr int PIPE_WIDTH = 49;
    static constexpr int PIPE_HEIGHT = 250;
    static constexpr int PIPE_GAP = 230;
    static constexpr int PIPE_SPEED = 3;
};

#endif
