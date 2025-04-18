#pragma once
#include <iostream>
#include <map>
#include <string>
#include <SDL_ttf.h>
using namespace std;
class TextManager
{

	
	static TextManager* instance;
	SDL_Color textColor;
	TTF_Font* gFont = nullptr;
public:





	TextManager();

	static TextManager* Get() {

		if (instance == 0)
		{
			instance = new TextManager();
			return instance;
		}
		return instance;
	}

	void renderText(const std::string& text, int x, int y, int size = 14, SDL_Renderer* myrenderer = nullptr);

	void changeFontColor(unsigned char R, unsigned char G, unsigned char B);

	~TextManager();

    

      


};

