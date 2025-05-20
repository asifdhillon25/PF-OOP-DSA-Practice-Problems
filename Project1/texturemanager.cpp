#include "texturemanager.h"



bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

    if (pTempSurface == 0)
    {
        std::cout << IMG_GetError();
        return false;
    }

    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

    SDL_FreeSurface(pTempSurface);

    if (pTexture != 0)
    {
        mymap[id] = pTexture;
        return true;
    }

    return false;
}


bool TextureManager::loadimage(string imagename,string id,SDL_Renderer* myrendrr)
{
    SDL_Surface* tempsurface = IMG_Load(imagename.c_str());
    if (tempsurface == 0)
    {
        return false;
    }

    SDL_Texture* mytexture = SDL_CreateTextureFromSurface(myrendrr, tempsurface);
    SDL_FreeSurface(tempsurface);
    if (tempsurface != 0)
    {
        mymap[id] = mytexture;
        return true;
    }


    return false;
}

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer* myrendrr, SDL_RendererFlip flip )
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(myrendrr, mymap[id], &srcRect,
        &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, 
    int currentRow, int currentFrame, SDL_Renderer* myrendrr, SDL_RendererFlip flip)
{

    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(myrendrr, mymap[id], &srcRect,
        &destRect, 0, 0, flip);
}

void TextureManager::clearFromTextureMap(std::string id)
{
    mymap.erase(id);
}
TextureManager* TextureManager::instance = 0;