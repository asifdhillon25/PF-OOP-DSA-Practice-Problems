#pragma once

#include "texturemanager.h"
#include <iostream>
#include "LoaderParams.h"
#include<SDL.h>
#include "MainGame.h"
#include "Vector2D.h"


class Bullet:public MainGame
{
public:
	Bullet();
	void load(const LoaderParams* myparam, Vector2D Direction);
	void draw();
	void update();
	void clean();
	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }
	bool& GetDeadState() { return MainGame::GetDeadState(); }
	void collision() { MainGame::collision(); }
	~Bullet(){}
};

class EnemyBullet :public Bullet
{//inherit from bullet acess all its functions and its unique Vector is in bulletmanager class
public:
	EnemyBullet():Bullet(){}
	~EnemyBullet()
	{

	}

};