#pragma once
#include "SDL_ttf.h"
#include <vector>

class Text;
static class TextManager
{
	
public:
	static void Init();
	static void CleanUp();
	static void Render();
	static Text* AddText(int x, int y, const char* text);

	static TTF_Font* font;
	static std::vector<Text*> allText;
};

