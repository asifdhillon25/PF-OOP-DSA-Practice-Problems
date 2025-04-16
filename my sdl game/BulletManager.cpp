#include "BulletManager.h"
#include "LoaderParams.h"
BulletManager* BulletManager:: cinstance = new BulletManager();

void BulletManager::addPlayerbullet(int x, int y, int width, int height, std::string textureID, int numFrames,Vector2D Direction)
{
	

	Bullet* newbullet = new Bullet;
	newbullet->load(new LoaderParams(x, y, width, height, textureID, numFrames),Direction);

	PlayerBullets.push_back(newbullet);
}

void BulletManager::addEnemubullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D Direction)
{
	EnemyBullet* newBullet = new EnemyBullet();
	newBullet->load(new LoaderParams(x, y, width, height, textureID, numFrames), Direction);
	EnemyBullets.push_back(newBullet);
}

void BulletManager::updateBullets()
{
	for (vector<Bullet*>::iterator it = PlayerBullets.begin(); it != PlayerBullets.end();)
	{
		if ((*it)->Getposition().getY() < 18|| (*it)->GetDeadState())
		{
			delete (*it);
			it = PlayerBullets.erase(it);
		}
		else
		{
			(*it)->update();
			++it;
		}
	}

		for (vector<EnemyBullet*>::iterator it = EnemyBullets.begin(); it != EnemyBullets.end();)
		{
			if ((*it)->Getposition().getY() >720-11|| (*it)->GetDeadState())
			{
				delete (*it);
				it = EnemyBullets.erase(it);
			}
			else
			{
				(*it)->update();
				++it;
			}
		}
}

void BulletManager::drawBullets()
{

	for (int i = 0; i < PlayerBullets.size(); i++)
	{
		PlayerBullets[i]->draw();
	}


	for (int i = 0; i < EnemyBullets.size(); i++)
	{
		EnemyBullets[i]->draw();
	}
}

void BulletManager::clearBullets()
{
	PlayerBullets.clear();
	EnemyBullets.clear();
}
