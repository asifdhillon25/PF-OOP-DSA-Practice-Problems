#include "EnemyManager.h"

 EnemyManager* EnemyManager::instance = new EnemyManager;
 
void EnemyManager::init()
{
	int x; int y;
	x = myposition.getX();
	y = myposition.getY();

	for (int i = 0; i < enemyCount; i++)
	{
		enemytype1* newEnemy = new enemytype1;
		newEnemy->load(new LoaderParams(x,y , m_width, m_height, m_textureID, m_numFrames));
		myenemyvect.push_back(newEnemy);
		
		x += m_width;
	
	}
	
	
}

void EnemyManager::load(const LoaderParams* myparam)
{
	m_width = myparam->getWidth();
	m_height = myparam->getHeight();
	m_textureID = myparam->getTextureID();
	m_currentFrame = 0;
	m_numFrames = myparam->getNumFrames();
	myposition = Vector2D(myparam->getX(), myparam->getY());
}

void EnemyManager::draw()
{
	for (int i=0;i<myenemyvect.size();i++)
	{
		myenemyvect[i]->draw();
	}
}

void EnemyManager::update()
{
	for (vector<enemytype1*>::iterator it=myenemyvect.begin(); it!=  myenemyvect.end();)
	{
		if ((*it)->GetDeadState() )
		{
			delete* it;
			it = myenemyvect.erase(it);
		}
		else
		{
			(*it)->update();
			++it;
		}
	}
}

void EnemyManager::clean()
{
	for (int i = 0; i < myenemyvect.size(); i++)
	{
		myenemyvect[i]->clean();
	}
}
