#include "TextManager.h"
#include "Game.h"
#include "Text.h"

#include <iostream>


TTF_Font* TextManager::font;
std::vector<Text*> TextManager::allText;



void TextManager::Init()
{

	if (TTF_Init() < 0) {
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}

	font = TTF_OpenFont("assets/Lato-Regular.ttf", 24);
	if (!font) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
	}

}

void TextManager::CleanUp()
{
	for (Text* text : allText) {
		delete text;
	}
	TTF_CloseFont(font);
	TTF_Quit();
}

void TextManager::Render() {
	for (Text* text : allText) {
		text->render();
	}
}

Text* TextManager::AddText(int x, int y, const char* text)
{
	Text* newText = new Text(x, y, text);
	allText.push_back(newText);
	return newText;
}
