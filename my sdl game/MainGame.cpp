#include "MainGame.h"
#include "Game.h"

MainGame::MainGame():GameBase(),myposition(0,0),myvelocity(0,0),myacceleration(0,0),Direction(0,0)
{


}

void MainGame::draw()
{
	
	Load::Get()->drawFrame(m_textureID, myposition.getX(), myposition.getY(), m_width, m_height, 0, m_currentFrame, Game::instance()->getRendrer(), SDL_FLIP_NONE);
		
	
}

void MainGame::update()
{
	myvelocity += myacceleration;
	myposition += myvelocity;
}

void MainGame::clean()
{

	TextureManager::Get()->clearFromTextureMap(m_textureID);
}

void MainGame::load(const LoaderParams* myparam)
{
	myposition = Vector2D(myparam->getX(), myparam->getY());
	myvelocity = Vector2D(0, 0);
	myacceleration = Vector2D(0, 0);
	m_width = myparam->getWidth();
	m_height = myparam->getHeight();
	m_textureID = myparam->getTextureID();
	m_currentFrame = 0;
	m_numFrames = myparam->getNumFrames();

}

void MainGame::collision()
{
	isDead = true;
}
