#pragma once
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
#include "MenuBase.h"
#include "GameObjectFactory.h"

class PauseState : public MenuState
{
public:
	virtual void update();
	virtual void setCallbacks(const std::vector<Callback>& callbacks);
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
};


