#include "Player.h"

Player::Player() :
	SDLGameObject()
{
	
}

void Player::load(const LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
}
void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 8));
	
	TheInputHandler::Instance()->update();
	
	

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		float i= m_position.getX();
		i += 4;
		m_velocity.setX(i);
		
		
		
	}
	else
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		float i = m_position.getX();
		i -= 4;

		m_velocity.setX(i);
		
		
	}
	else
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		float i = m_position.getY();
		i -= 4;
		m_velocity.setY(i);
		
	}
	else
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		float i = m_position.getY();
		i += 4;
		m_velocity.setY(i);

	}
	handleInput();
	SDLGameObject::update();
}
void Player::clean()
{
}

void Player::handleInput()
{
	Vector2D target = TheInputHandler::Instance()
		->getMousePosition();
	m_velocity = target - m_position;
	m_velocity /= 50;
}