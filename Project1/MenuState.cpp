#include "MenuState.h"
#include "Class.h"


const std::string MainMenuState::s_menuID = "MENU";
void MainMenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}



	void MainMenuState::render()
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->draw();
		}
	}


	void MainMenuState::setCallbacks(const std::vector<Callback>&
		callbacks)
	{
		cout << "setcall calles\n";
		// go through the game objects
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			// if they are of type MenuButton then assign a callback 
			
				if (dynamic_cast<MenuButton*>(m_gameObjects[i]))
				{
					cout << "setcall calles\n";
					MenuButton* pButton =
						dynamic_cast<MenuButton*>(m_gameObjects[i]);
					pButton->setCallback(callbacks[pButton->getCallbackID()]);
				}
		}
	}

	bool MainMenuState::onEnter()
	{
		// parse the state
		StateParser stateParser;
		stateParser.parseState("test.xml", s_menuID, &m_gameObjects,
			&m_textureIDList);
		
		m_callbacks.push_back(0); //pushback 0 callbackID start from 1
		m_callbacks.push_back(s_menuToPlay);
		m_callbacks.push_back(s_exitFromMenu);
		// set the callbacks for menu items
		setCallbacks(m_callbacks);
		std::cout << "entering MenuState\n";
		return true;
	}





	bool MainMenuState::onExit()
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			m_gameObjects[i]->clean();
		}
		m_gameObjects.clear();
		TextureManager::Get()
			->clearFromTextureMap("playbutton");
		TextureManager::Get()
			
		->clearFromTextureMap("exitbutton");
		std::cout << "exiting MenuState\n";


		// clear the texture manager
		for (int i = 0; i < m_textureIDList.size(); i++)
		{
			TextureManager::Get()->
				clearFromTextureMap(m_textureIDList[i]);
		}
		return true;
	}

	
	void MainMenuState::s_exitFromMenu()
	{
		TheGame::Instance()->quit();
	}

	void MainMenuState::s_menuToPlay()
	{
		TheGame::Instance()->getStateMachine()->changeState(new
			PlayState());
	}