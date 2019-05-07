#include "../include/Game.h"

#include <iostream>
#include "../include/TileMap.h"
#include "../../entity-component-system/components/include/TransformComponent.h"
#include "../../entity-component-system/components/include/SpriteComponent.h"
#include "../../entity-component-system/components/include/KeyboardControllerComponent.h"
#include "../../entity-component-system/components/include/ColliderComponent.h"
#include "entities/include/Entity.h"
#include "../../physics/include/Collision.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

SDL_Renderer* Game::getRenderer() {
    return renderer;
}

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
    initScene();
    playerEntity = &manager.addEntity();
    playerEntity->addComponent<TransformComponent>(300,0);
    playerEntity->addComponent<SpriteComponent>("resources/assets/chrono.png");
    playerEntity->addComponent<KeyboardControllerComponent>();
    playerEntity->addComponent<ColliderComponent>("player");

    wallEntity = &manager.addEntity();
    wallEntity->addComponent<TransformComponent>(200.0f,200.0f, 20, 200, 1);
    wallEntity->addComponent<SpriteComponent>("resources/assets/tiles/sand.png");
    wallEntity->addComponent<ColliderComponent>("wall");

}

void Game::handleEvents() {
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
    manager.refresh();
    manager.update();

    if (Collision::AABB(playerEntity->getComponent<ColliderComponent>().getCollider(),
                        wallEntity->getComponent<ColliderComponent>().getCollider())) {
        playerEntity->getComponent<TransformComponent>().setScale(1);
                        }
}

void Game::render() {
	SDL_RenderClear(renderer);
	tileMap->draw();
	manager.draw();
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;

}
bool Game::running() {
	return isRunning;
}

void Game::initScene() {
    tileMap = new TileMap(20, 25);
}
