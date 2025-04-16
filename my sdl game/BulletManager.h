#pragma once
#include "Bullet.h"

#include <vector>
class BulletManager
{
public:
	void addPlayerbullet(int x, int y, int width, int height, std::string textureID, int numFrames,  Vector2D Direction);
	void addEnemubullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D Direction);
	static BulletManager* Get()
	{
		if (cinstance == 0)
		{
			cinstance = new BulletManager();
			return cinstance;
		}
		return cinstance;
	}
	void updateBullets();

	void drawBullets();
	void clearBullets();
	vector<Bullet*> GetBullet() {
		return PlayerBullets;
	}


	vector<EnemyBullet*> GetEnemyBullet() 
	{
		return EnemyBullets;
	}
private:
	static  BulletManager* cinstance;
	vector<Bullet*> PlayerBullets;
	vector<EnemyBullet*>EnemyBullets ;
};

