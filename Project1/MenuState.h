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
#include "tinyxml.h"
#include "StateParser.h"

class MainMenuState : public MenuState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
private:
	virtual void setCallbacks(const std::vector<Callback>&
		callbacks);
	// call back functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
};
