#pragma once

#include "GameState.h"
#include<SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "texturemanager.h"
#include "Player.h"
#include "GameObject.h"
#include "Enemy.h"
#include "SDLGameObject.h"
#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "PauseState.h"
#include "AnimatedGraphic.h"
#include "MenuBase.h"
#include "GameObjectFactory.h"


class GameOverState : public MenuState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual void setCallbacks(const std::vector<Callback>& callbacks);

	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }
private:
	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;
};

