#pragma once
#include<SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "texturemanager.h"
#include "Player.h"
#include "GameObject.h"
#include "Enemy.h"
#include "SDLGameObject.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameObjectFactory.h"
using namespace std;
class GAME
{
	
private:
	SDL_Window* mywindow;
	SDL_Renderer* myrendrr;
	bool m_bRunning;
	SDL_Texture* mytexture;
	SDL_Rect sourcerect;
	SDL_Rect destinationrect;
	int m_currentFrame;
	
	vector<GameObject*> m_gameObjects;
	GAME() {
	
		m_bRunning = true;
	};
	// create the s_pInstance member variable
	static GAME* s_pInstance;
	// create the typedef
	GameStateMachine* m_pGameStateMachine;

public:
	SDL_Renderer* getRenderer() const { return myrendrr; } 

	static GAME* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GAME();
			return s_pInstance;
		}
		return s_pInstance;
	}
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

	bool init(const char* title, int xpos, int ypos, int width,
		int height, int flags);
	void render();
	
	void update();
	void handleEvents();
	void clean();
	bool running();
	void quit()
	{
		m_bRunning = false;
	}
	
};

typedef GAME TheGame;