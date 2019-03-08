#include "Game.h"

#include <iostream>

#include "GameObject.h"

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!..." << std::endl;

		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;

	} else {
		isRunning = false;
	}
    player = new GameObject("assets/megaman.png", renderer, 20, 20);
}
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::update() {
    player->update();
}
void Game::render() {
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
    delete player;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
bool Game::running() {
	return isRunning;
}
