#pragma once
#include <iostream>
#include<SDL.h>
#include "Player.h"
#include "LoaderParams.h"
#include <vector>
#include "MainGame.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "Collision.h"


class CollisionManager
{
public:

	void CheckPlayerEnemyCollision(Player *player);
	void CheckBulletEnemyollision();
	void CheckBulletPlayerCollision(Player* player);



	

};

