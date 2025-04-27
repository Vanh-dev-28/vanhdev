#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "game.h"

int main(int argc, char* argv[]) {
    Game game;
    game.init();

    if (!game.running) {
        return -1;
    }

    while (game.running) {
        game.handleEvents();
        game.render();
        game.update();
        SDL_Delay(16);
    }

    game.clean();
    return 0;
}
