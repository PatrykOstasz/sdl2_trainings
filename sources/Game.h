#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include "SDL.h"

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif GAME_H_
