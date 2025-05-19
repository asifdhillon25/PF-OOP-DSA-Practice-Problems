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
class AnimatedGraphic:public SDLGameObject
{

	int m_animSpeed;
	int m_numFrames;
public:


	AnimatedGraphic();

	void load(const LoaderParams* pParams);

	void update();
};

