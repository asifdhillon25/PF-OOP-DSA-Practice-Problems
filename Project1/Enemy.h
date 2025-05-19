#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"


class Enemy :public SDLGameObject 
{
	
	
	public:
		Enemy();
		void load(const LoaderParams* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();
	
};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};