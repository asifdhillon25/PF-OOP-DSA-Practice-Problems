#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "Player.h"
#include "LoaderParams.h"
#include <vector>
#include "MainGame.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "CollisionManager.h"
#include "TextManager.h"

using namespace std;

class Game
{
	SDL_Renderer* myrendrer;
	SDL_Window* mywindow;
	
	bool Gamerunning;
	static Game* myinstance;
	std::vector<MainGame*> GameVect;
	Vector2D *playerposition;
	vector<Bullet*> BulletVect;
	Player* playercheck;
	CollisionManager collisionManager;
	Game();
		
	
	
public:

	bool Init(const char* title, int x, int y, int w, int h, int flags);
	void update();
	void rendrer();
	void clean();
	void events();
	bool GameRun() { return Gamerunning; }
	void quit() { Gamerunning = false; }
	SDL_Renderer* getRendrer() { return myrendrer; }
	static Game* instance()
	{
		if (myinstance == 0)
		{
			myinstance = new Game();
			return myinstance;
		}
		return myinstance;
	}





};
typedef Game TheGame;

