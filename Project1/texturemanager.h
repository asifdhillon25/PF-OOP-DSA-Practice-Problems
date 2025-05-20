#pragma once
#include<SDL.h>
#include <SDL_image.h>
#include <iostream>
#include<map>
using namespace std;

class TextureManager
{
private:

	TextureManager() {}
	map<string, SDL_Texture*> mymap;
	static TextureManager* instance;
public:
	

	static TextureManager* Get() {
		
		if (instance == 0)
		{
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	bool loadimage(string imagename,string id, SDL_Renderer* myrendrr);
	void draw(string id, int x, int y, int width, int height, SDL_Renderer* myrendrr
		,SDL_RendererFlip );
	void drawFrame(string id, int x, int y, int width, int
		height, int currentRow, int currentFrame, SDL_Renderer* myrendrr,
		SDL_RendererFlip flip );
	void clearFromTextureMap(std::string id);
};

