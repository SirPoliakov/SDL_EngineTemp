#pragma once

#include <SDL_rect.h>
enum  Color {Red, White, Grey, Brown, None};

struct Rectangle
{
	float x;
	float y;
	float width;
	float height;
	Color color;

	Rectangle() : x(0), y(0), width(0), height(0), color(None) {};
	Rectangle(float _x, float _y, float _w, float _h, Color _c) : x(_x), y(_y), width(_w), height(_h), color(_c){}

	SDL_Rect toSDLRect() const
	{
		return SDL_Rect{
			static_cast<int>(x),
			static_cast<int>(y),
			static_cast<int>(width),
			static_cast<int>(height)
		};
	}
};