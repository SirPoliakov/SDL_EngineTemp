#pragma once
#include "Window.h"
#include "Renderer.h"

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
		wallThickness(10)
	{}
		


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
};