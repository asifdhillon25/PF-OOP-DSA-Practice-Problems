#include "Enemy.h"
#include "Constants.h"
#include <cstdlib> // For rand() function
#include <ctime> 
#include "BulletManager.h"
 Enemy::Enemy() :MainGame() {
	 srand(time(0));
 }

void Enemy::load(const LoaderParams* myparam)
{
	MainGame::load(myparam);
}

void Enemy::draw()
{
	MainGame::draw();
}

void Enemy::update()
{
	
	if (flAG==true)
	{
		myposition.m_x += 5;
		if (myposition.getX() >= ScreenWidth)
			flAG = false;
	}
	else if (flAG == false)
	{
		myposition.m_x -= 5;
		if (myposition.getX() <= 0)
			flAG = true;
	}
	int randomNumber = rand() % 500;

	// The following condition allows bullets to be added at random intervals
	if (randomNumber == 0)
	{
		// Adjust the parameters according to your requirements
		BulletManager::Get()->addEnemubullet(myposition.getX(), myposition.getY()-22, 11, 11, "bullet", 0, Vector2D(0, 2));
	}

	MainGame::update();
	if(myposition.getX()>0 && myposition.getX() < ScreenWidth)

	m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
}

void Enemy::clean()
{
	MainGame::clean();
}
