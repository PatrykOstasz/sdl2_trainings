#ifndef GAME_H_
#define GAME_H_

#include "SDL.h"
#include "SDL_image.h"

class GameObject;

class Game {
public:
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
	GameObject* player;
};

#endif GAME_H_
