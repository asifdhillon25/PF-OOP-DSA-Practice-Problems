#pragma once
#include "Enemy.h"
 // For time() function
#include "BulletManager.h"
class enemytype1:public Enemy
{

public:

	enemytype1();

	void load(const LoaderParams* myparam);
	void draw();
	void update();
	void clean();

};

