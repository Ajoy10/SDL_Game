#include "Text.h"
#include "TextManager.h"
#include "Game.h"


Text::Text(float x, float y, const char* text)
{
	this->x = x;
	this->y = y;
	this->text = text;
	GenerateTexture();
}

void Text::GenerateTexture() {
	SDL_Color color = { 255,255,255,255 };
	

	this->surface = TTF_RenderText_Solid(TextManager::font, this->text, color);
	if (this->surface == NULL) {
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
	}

	this->texture = SDL_CreateTextureFromSurface(Game::renderer, surface);


}

void Text::ChangeText(const char* text)
{
	this->text = text;
}

void Text::render()
{
	SDL_Rect dest;
	dest.x = x - (surface->w / 2);
	dest.y = y - (surface->h / 2);
	dest.w = surface->w * 4;
	dest.h = surface->h * 4;

	SDL_RenderCopy(Game::renderer, texture, NULL, &dest);
}

Text::~Text() {
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}
