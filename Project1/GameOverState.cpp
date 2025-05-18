#include "GameOverState.h"
#include "Class.h"
const std::string GameOverState::s_gameOverID = "GAMEOVER";
void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new
		MainMenuState());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new
		PlayState());
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();

	}
}

//bool GameOverState::onEnter()
//{
//	if (!TextureManager::Get()->loadimage("assets/gam.png",
//		"gameovertext", TheGame::Instance()->getRenderer()))
//	{
//		return false;
//	}
//	if (!TextureManager::Get()->loadimage("assets/man.jpg",
//		"mainbutton", TheGame::Instance()->getRenderer()))
//	{
//		return false;
//	}
//	if (!TextureManager::Get()->loadimage("assets/rest.jpg",
//		"restartbutton", TheGame::Instance()->getRenderer()))
//	{
//		return false;
//	}
//	GameObject* gameOverText = new AnimatedGraphic(new
//		LoaderParams(477, 35, 190, 30, "gameovertext"), 2,2);
//
//	GameObject* button1 = new MenuButton(new LoaderParams(200, 200,
//		162, 67, "mainbutton"), s_gameOverToMain);
//
//	GameObject* button2 = new MenuButton(new LoaderParams(200, 300,
//		162, 63, "restartbutton"), s_restartPlay);
//
//	m_gameObjects.push_back(gameOverText);
//	
//	m_gameObjects.push_back(button1);
//	m_gameObjects.push_back(button2);
//	std::cout << "entering gameoverState\n";
//	return true;
//}

bool GameOverState::onEnter()
{
	// parse the state
	StateParser stateParser;
	stateParser.parseState("test.xml", s_gameOverID, &m_gameObjects,
		&m_textureIDList);
	
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);
	// set the callbacks for menu items
	setCallbacks(m_callbacks);
	std::cout << "entering PauseState\n";
	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based 

		if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton =
				dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	for (int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Get()->
			clearFromTextureMap(m_textureIDList[i]);
	}

	// reset the mouse button states to false
	//TheInputHandler::Instance()->reset();
	std::cout << "exiting gameoverState\n";
	return true;

	
}
