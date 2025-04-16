#pragma once
#include "TextManager.h"
#include "texturemanager.h"
#include <iostream>
#include "LoaderParams.h"
#include<SDL.h>
#include "MainGame.h"
#include "Bullet.h"
using namespace std;


class Player:public MainGame
{  

	
	
public:

	Player();
	void load(const LoaderParams* myparam);
	void draw();
	void update();
    void clean();
	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }
	bool& GetDeadState() { return MainGame::GetDeadState();}
	void collision() { MainGame::collision(); }
};

