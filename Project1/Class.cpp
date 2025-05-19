#include "Class.h"

GAME* GAME::s_pInstance = 0;





bool GAME::init(const char* title, int xpos, int ypos, int width,
	int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		mywindow = SDL_CreateWindow(title, xpos, ypos, width, height,
			flags);



		if (mywindow)
		{
			myrendrr = SDL_CreateRenderer(mywindow, -1, 0);
		}
		else
		{
			cout << "window creation failed\n";
		}


		if (myrendrr != 0)
		{
			SDL_SetRenderDrawColor(myrendrr, 0,5, 155, 255);
		}
		else
		{
			cout << "render creation failed\n";
		}

		cout << "sdl init succcess\n";
		

		GameObjectFactory::Instance()->registerType("MenuButton", new
			MenuButtonCreator());
		cout << "register\n";
		GameObjectFactory::Instance()->registerType("Player", new
			PlayerCreator());
		GameObjectFactory::Instance()->registerType("Enemy", new
			EnemyCreator());



		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(new MainMenuState());

		

		
	}
	else
	{
		cout << "sdl init creation failed\n";
		return 0;
	}

}



void GAME::render()
{
	SDL_RenderClear(myrendrr); // clear the renderer to 

	m_pGameStateMachine->render();
	//m_textureManager.draw("animation", 0, 0, 326, 542, myrendrr, SDL_FLIP_NONE);
	/*for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/


	SDL_RenderPresent(myrendrr);
}

void GAME::update()
{
	/*m_pGameStateMachine->update();
	for (std::vector<GameObject*>::size_type i = 0; i !=
		m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/
	m_pGameStateMachine->update();
}

void GAME::handleEvents()
{
	/*TheInputHandler::Instance()->update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}*/
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void GAME::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(mywindow);
	SDL_DestroyRenderer(myrendrr);
	SDL_Quit();
}

bool GAME::running()
{
	return m_bRunning;
}
