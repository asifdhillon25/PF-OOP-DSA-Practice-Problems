#include "texturemanager.h"






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
        cout << "id" << endl;
        return true;
    }


    return false;
}



void TextureManager::drawFrame(string id, int x, int y, int width, int height, 
    int currentRow, int currentFrame, SDL_Renderer* myrendrr, SDL_RendererFlip flip)
{

    /*SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;

    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;*/

    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * currentRow;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;


    SDL_RenderCopyEx(myrendrr, mymap[id], &srcRect,
        &destRect, 0, 0, flip);
    SDL_RenderCopyEx(myrendrr, mymap[id], &srcRect,
        &destRect, 0, 0, flip);
    
}

void TextureManager::clearFromTextureMap(std::string id)
{
    mymap.erase(id);
}
TextureManager* TextureManager::instance = 0;