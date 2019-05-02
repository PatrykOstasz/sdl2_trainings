#ifndef GAME_H_
#define GAME_H_

#include "SDL.h"
#include "SDL_image.h"
#include "../../entity-component-system/SystemManager.h"

class Entity;
class TileMap;

class Game {
public:
	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running();
	static SDL_Renderer* getRenderer();

private:
    void initScene();

	bool isRunning;
	SDL_Window* window;
	static SDL_Renderer* renderer;
	TileMap* tileMap;
	Entity* playerEntity;
	SystemManager manager;
};

#endif GAME_H_
