#include "../include/Game.h"

#include <stdint.h>

int main(int argc, char** argv) {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    uint32_t frameStart;
    int frameTime;

    Game* game = new Game();
	game->init("Hej", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);
	while (game->running()) {

        frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return 0;
}
