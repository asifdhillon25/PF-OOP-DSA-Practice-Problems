#include "TextManager.h"
#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

TextManager* TextManager::instance = 0;

TextManager::TextManager()
{
    
          
    textColor = { 255, 255, 255 }; // White color
    
    
    
}






void TextManager::renderText(const std::string& text, int x, int y, int size, SDL_Renderer* myrenderer)
{
    gFont = TTF_OpenFont("assets/p2p.ttf", size);
    if (gFont == nullptr) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    if (myrenderer == nullptr) {
        myrenderer = Game::instance()->getRendrer();
    }

    

    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text.c_str(), textColor);
    if (!textSurface) {
        std::cerr << "Failed to render text. TTF Error: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(myrenderer, textSurface);
    if (!textTexture) {
        std::cerr << "Failed to create texture from surface. SDL Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Rect renderQuad = { x, y, textSurface->w, textSurface->h };
    SDL_RenderCopy(myrenderer, textTexture, nullptr, &renderQuad);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}



void TextManager::changeFontColor(unsigned char R, unsigned char G, unsigned char B)
{
    textColor = { R, G, B };
}



TextManager::~TextManager()
{
    
}