#include "Renderer.h"
#include "Log.h"

Renderer::Renderer() : SDLRenderer(nullptr)
{
}

bool Renderer::initialize(Window& window)
{
	SDLRenderer = SDL_CreateRenderer(window.getSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!SDLRenderer)
	{
		Log::error(LogCategory::Video, "Failed to create renderer");
		return false;
	}
	return true;
}

void Renderer::beginDraw()
{
	SDL_SetRenderDrawColor(SDLRenderer, 0, 0, 0, 255);
	SDL_RenderClear(SDLRenderer);
}

void Renderer::endDraw()
{
	SDL_RenderPresent(SDLRenderer);
}

void Renderer::drawRect(Rectangle& rect)
{
	if (rect.color == Red) { drawRectRed(rect); }
	if (rect.color == White) { drawRectWhite(rect); }
	if (rect.color == Grey) { drawRectGrey(rect); }
	if (rect.color == Brown) { drawRectBrown(rect); }
}

void Renderer::drawRectRed(Rectangle& rect)
{
	SDL_SetRenderDrawColor(SDLRenderer, 255, 0, 0, 255);
	SDL_Rect SDLRect = rect.toSDLRect();
	SDL_RenderFillRect(SDLRenderer, &SDLRect);
}

void Renderer::drawRectGrey(Rectangle& rect)
{
	SDL_SetRenderDrawColor(SDLRenderer, 80, 80, 80, 255);
	SDL_Rect SDLRect = rect.toSDLRect();
	SDL_RenderFillRect(SDLRenderer, &SDLRect);
}

void Renderer::drawRectBrown(Rectangle& rect)
{
	SDL_SetRenderDrawColor(SDLRenderer, 139, 69, 19, 255);
	SDL_Rect SDLRect = rect.toSDLRect();
	SDL_RenderFillRect(SDLRenderer, &SDLRect);
}

void Renderer::drawRectWhite(Rectangle& rect)
{
	SDL_SetRenderDrawColor(SDLRenderer, 255, 255, 255, 255);
	SDL_Rect SDLRect = rect.toSDLRect();
	SDL_RenderFillRect(SDLRenderer, &SDLRect);
}


void Renderer::close()
{
	SDL_DestroyRenderer(SDLRenderer);
}