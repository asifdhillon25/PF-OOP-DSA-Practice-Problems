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
#include "GameOverState.h"

#include "tinyxml.h"

class StateParser
{
public:
	StateParser();
	~StateParser();
	bool parseState(const char* stateFile, string stateID,
		std::vector<GameObject*>* pObjects, std::vector<std::string>
		* pTextureIDs);
private:
	void parseObjects(TiXmlElement* pStateRoot,
		vector<GameObject*>* pObjects);
	void parseTextures(TiXmlElement* pStateRoot,
		std::vector<string>* pTextureIDs);
};

