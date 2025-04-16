#pragma once
#include "enemytype.h"
#include <vector>
#include "Vector2D.h"
#include <string>
using namespace std;

class EnemyManager
{
public:
	void init();
	void load(const LoaderParams* myparam);
	void draw();
	void update();
	void clean();
	vector<enemytype1*> GetEnemy() {

		return myenemyvect;
	}
	static EnemyManager* Instance()
	{
		if (instance == 0)
		{
			instance = new EnemyManager();
			return instance;
		}
		return instance;
	}
private:
	int enemyCount=10;
	vector<enemytype1*> myenemyvect;
	Vector2D myposition;
	int m_currentRow;
	int m_currentFrame;
	int m_width;
	int m_height;

	int m_callbackID;
	int m_animSpeed;

	std::string m_textureID;
	static EnemyManager* instance;
	int m_numFrames;
};

