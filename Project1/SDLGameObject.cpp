#include "SDLGameObject.h"
#include "Class.h"



SDLGameObject::SDLGameObject() :
	GameObject()	
{
	
}
void SDLGameObject::load(const LoaderParams* pParams)
{
	m_position = Vector2D(pParams->getX(), pParams->getY());
	m_velocity = Vector2D(0, 0);
	m_acceleration = Vector2D(0, 0);
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 1;
	m_currentFrame = 1;
	m_numFrames = pParams->getNumFrames();
}
//void SDLGameObject::draw()
//{
//	TextureManager::Get()->drawFrame(m_textureID,
//		(int)m_position.getX(), (int)m_position.getY(), m_width,
//		m_height, m_currentRow, m_currentFrame,
//		TheGame::Instance()->getRenderer(),SDL_FLIP_NONE);
//}

void SDLGameObject::draw()
{
	if (TheGame::Instance()->getStateMachine()->getid() == "PLAY")
	{
		if (m_velocity.getX() > 0)
		{
			TextureManager::Get()->drawFrame(m_textureID,
				(Uint32)m_position.getX(), (Uint32)m_position.getY(),
				m_width, m_height, m_currentRow, m_currentFrame,
				TheGame::Instance()->getRenderer(), SDL_FLIP_NONE);
		}
		else
		{
			TextureManager::Get()->drawFrame(m_textureID,
				(Uint32)m_position.getX(), (Uint32)m_position.getY(),
				m_width, m_height, m_currentRow, m_currentFrame,
				TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
		}
	}
	else
	{
		TextureManager::Get()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(), SDL_FLIP_NONE);
	}
	
}


void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::clean()
{
}
