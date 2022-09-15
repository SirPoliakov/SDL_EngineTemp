#include "Game.h"

bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);

	int windowWidth = window.getWidth();
	int windowHeight = window.getHeight();
	topWall = { 0, 0, static_cast<float>(windowWidth), wallThickness };
	bottomWall = { 0, windowHeight - wallThickness, static_cast<float>(windowWidth), wallThickness };
	rightWall = { windowWidth - wallThickness, 0, wallThickness, static_cast<float>(windowHeight) };
	leftWall = {0, 0, wallThickness, static_cast<float>(windowHeight) };

	return isWindowInit && isRendererInit; // Return bool && bool && bool ...to detect error
}

void Game::loop()
{
	while (isRunning)
	{
		processInput();
		update();
		render();
	}
}

void Game::close()
{
	renderer.close();
	window.close();
	SDL_Quit();
}

void Game::processInput()
{
	// SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}

	// Keyboard state
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	// Escape: quit game
	if (keyboardState[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}
}

void Game::update()
{
}

void Game::render()
{
	renderer.beginDraw();

	renderer.drawRectRed(topWall);
	renderer.drawRectRed(bottomWall);
	renderer.drawRectRed(rightWall);
	renderer.drawRectRed(leftWall);


	renderer.endDraw();
}