#include <iostream>
#include "Game.h"
using namespace std;

const int FPS = 60;
int FrameTime = 1000 / FPS;



int main(int argc, char* args[])
{
	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		if (TheGame::instance()->Init("myfirstwindow", 0, 0, 1280, 720,
			SDL_WINDOW_FULLSCREEN_DESKTOP))
		{
			Uint32 frameStart, frameTime;
			while (TheGame::instance()->GameRun())
			{
				frameStart = SDL_GetTicks();

				TheGame::instance()->events();
				TheGame::instance()->update();
				TheGame::instance()->rendrer();

				frameTime = SDL_GetTicks() - frameStart;


				if (FrameTime > frameTime)
				{
					SDL_Delay(FrameTime - frameTime);
				}
			}
		}
	}

	TheGame::instance()->clean();
	cout <<" closing Game main\n";
	return 0;
}
//
//#include <SDL.h>
//#include <SDL_ttf.h>
//#include <iostream>
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//SDL_Window* gWindow = nullptr;
//SDL_Renderer* gRenderer = nullptr;
//TTF_Font* gFont = nullptr;
//
//bool initSDL() {
//    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//        std::cerr << "SDL initialization failed. SDL Error: " << SDL_GetError() << std::endl;
//        return false;
//    }
//
//    gWindow = SDL_CreateWindow("SDL TTF Text Rendering", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    if (!gWindow) {
//        std::cerr << "Window creation failed. SDL Error: " << SDL_GetError() << std::endl;
//        return false;
//    }
//
//    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
//    if (!gRenderer) {
//        std::cerr << "Renderer creation failed. SDL Error: " << SDL_GetError() << std::endl;
//        return false;
//    }
//
//    if (TTF_Init() == -1) {
//        std::cerr << "SDL_ttf initialization failed. TTF Error: " << TTF_GetError() << std::endl;
//        return false;
//    }
//
//    return true;
//}
//
//bool loadFont(const std::string& fontPath, int fontSize) {
//    gFont = TTF_OpenFont(fontPath.c_str(), fontSize);
//    if (!gFont) {
//        std::cerr << "Failed to load font. TTF Error: " << TTF_GetError() << std::endl;
//        return false;
//    }
//    return true;
//}
//
//void closeSDL() {
//    TTF_CloseFont(gFont);
//    SDL_DestroyRenderer(gRenderer);
//    SDL_DestroyWindow(gWindow);
//    TTF_Quit();
//    SDL_Quit();
//}
//
//void renderText(const std::string& text, int x, int y) {
//    SDL_Color textColor = { 255, 255, 255 }; // White color
//
//    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text.c_str(), textColor);
//    if (!textSurface) {
//        std::cerr << "Failed to render text. TTF Error: " << TTF_GetError() << std::endl;
//        return;
//    }
//
//    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
//    if (!textTexture) {
//        std::cerr << "Failed to create texture from surface. SDL Error: " << SDL_GetError() << std::endl;
//        return;
//    }
//    cout << "texts  " << textSurface->h << endl;
//    SDL_Rect renderQuad = { x, y, textSurface->w, textSurface->h };
//    SDL_RenderCopy(gRenderer, textTexture, nullptr, &renderQuad);
//
//    SDL_FreeSurface(textSurface);
//    SDL_DestroyTexture(textTexture);
//}
//
//int main(int argc, char* args[]) {
//    if (!initSDL()) {
//        return 1;
//    }
//
//    if (!loadFont("assets/p2p.ttf", 28)) {
//        closeSDL();
//        return 1;
//    }
//
//    bool quit = false;
//    SDL_Event e;
//
//    while (!quit) {
//        while (SDL_PollEvent(&e) != 0) {
//            if (e.type == SDL_QUIT) {
//                quit = true;
//            }
//        }
//
//        // Clear the renderer
//        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255); // Black color
//        SDL_RenderClear(gRenderer);
//
//        // Render text
//        renderText("Hello, fghdfkjhg!", 100, 100);
//
//        // Update the screen
//        SDL_RenderPresent(gRenderer);
//    }
//
//    closeSDL();
//
//    return 0;
//}
