#include "Game.h"

bool Game::initialize()
{
	bool isWindowInit = window.initialize();
	bool isRendererInit = renderer.initialize(window);

	int windowWidth = window.getWidth();
	int windowHeight = window.getHeight();
	topWall = { 0, 0, static_cast<float>(windowWidth), wallThickness, Red };
	bottomWall = { 0, windowHeight - wallThickness, static_cast<float>(windowWidth), wallThickness, Red };
	rightWall = { windowWidth - wallThickness, 0, wallThickness, static_cast<float>(windowHeight), Red };
	leftWall = {0, 0, wallThickness, static_cast<float>(windowHeight), Red };
	
	int gridIndex = 0;

	for (int i = 8; i < 8+COLS; i++)
	{
		for (int j = 5; j < 5+ROWS; j++)
		{

			float squareLeftEdgeX = i * SQUARE_SIDE;
			float squareTopEdgeY = j * SQUARE_SIDE;
			grid[gridIndex].x = squareLeftEdgeX; grid[gridIndex].y = squareTopEdgeY;
			gridIndex++;

		}

	}

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

	//////////////////////----------------------------------  N O T   W O R K I N G  -------------------------------------///////////////////////////////

	// Mouse(X,Y) Coordonates
	int x, y;
	if (SDL_MOUSEMOTION == event.type)
	{
		
		SDL_GetMouseState(&x, &y);
		
	}

	// Getting out the left click button event for the tile color switch based on the mouse coordonates
	if (SDL_MOUSEBUTTONDOWN == event.type)
	{
		if (SDL_BUTTON_LEFT == event.button.button)
		{
			if ((x > 8 * SQUARE_SIDE) && (x < (8 + SQUARE_SIDE) * SQUARE_SIDE) && (y > 5 * SQUARE_SIDE) && (y < (5 + SQUARE_SIDE) * SQUARE_SIDE))
			{
				int tileCol = static_cast<int>((x / 35) - 8);
				int tileRow = static_cast<int>((y / 35) - 5);
				int index = tileCol + COLS * tileRow;
				grid[index].color = None;
			}
		}
	}

	//////////////////////----------------------------------  N O T   W O R K I N G  -------------------------------------///////////////////////////////


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

	renderer.drawRect(topWall);
	renderer.drawRect(bottomWall);
	renderer.drawRect(rightWall);
	renderer.drawRect(leftWall);

	for (int i = 0; i < COLS * ROWS; i++)
	{
		Rectangle tempRect = grid[i]; tempRect.width -= V_GAP; tempRect.height -= V_GAP;
		renderer.drawRect(tempRect);
	}

	renderer.endDraw();
}