#pragma once
#include "MainGame.h"
#include "GameBase.h"
#include "texturemanager.h"
#include <iostream>
#include "LoaderParams.h"
#include "Vector2D.h"
#include<SDL.h>


class Enemy:public MainGame
{
	bool flAG=true;
public:
	Enemy();

	void load(const LoaderParams* myparam);
	void draw();
	void update();
	void clean();
	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }
	bool& GetDeadState() { return MainGame::GetDeadState(); }
	void collision() { MainGame::collision(); }

};

