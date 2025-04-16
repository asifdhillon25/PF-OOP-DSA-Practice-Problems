#include "Bullet.h"
#include "Game.h"
#include "InputHandler.h"

Bullet::Bullet() : MainGame() {


	

}

void Bullet::load(const LoaderParams* myparam,Vector2D Direction)
{
	this->Direction = Direction;
	MainGame::load(myparam);
}

void Bullet::draw()
{
	MainGame::draw();
}

void Bullet::update()
{
	

	 if ( myposition.m_y > 0)
	{
		 myposition += Direction;

	}

	

	MainGame::update();
}

void Bullet::clean()
{
	MainGame::clean();
}


