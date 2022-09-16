#pragma once
#include "Window.h"
#include "Renderer.h"
#include <vector> 

using namespace std;

class Game
{
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

private:
	Game(): 
		isRunning(true),
		topWall(Rectangle()),
		bottomWall(Rectangle()),
		rightWall(Rectangle()),
		leftWall(Rectangle()),
		wallThickness(10),
		SQUARE_SIDE(35),
		V_GAP(4),
		ROWS(13),
		COLS(13)
	{
		for (int i = 0; i < COLS*ROWS; i++)
		{
			grid.push_back(Rectangle(0.0f, 0.0f, SQUARE_SIDE, SQUARE_SIDE, Grey));
		}
	}
		


public:
	bool initialize();
	void loop();
	void close();

private:
	void processInput();
	void update();
	void render();

	Window window;
	bool isRunning;
	Renderer renderer;

	Rectangle topWall;
	Rectangle bottomWall;
	Rectangle leftWall;
	Rectangle rightWall;
	const float wallThickness = 10;
	vector<Rectangle> grid;
	const float SQUARE_SIDE = 35;
	const float V_GAP = 4;
	const int COLS = 13;
	const int ROWS = 13;
};