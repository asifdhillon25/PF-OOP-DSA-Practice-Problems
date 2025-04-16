#include "Game.h"
#include "SoundManager.h"


Game* Game::myinstance = 0;

Game::Game()
{
	Gamerunning = true;
	
	
}

bool Game::Init(const char* title,int x,int y,int w,int h,int flags)
{
	
	
	
		mywindow = SDL_CreateWindow(title, x, y, w, h, flags);
	

	if (mywindow)
	{
		myrendrer = SDL_CreateRenderer(mywindow, -1, SDL_RENDERER_ACCELERATED);
	}
	TTF_Init();
	SDL_SetRenderDrawColor(myrendrer, 0, 5, 155, 255);
	
	TheSoundManager::Instance()->load("assets/phaser.wav", "shoot", SOUND_SFX);

	Load::Get()->loadimage("assets/jet.png", "redjet", getRendrer());
	Load::Get()->loadimage("assets/bullet1.png", "bullet", getRendrer());
	Load::Get()->loadimage("assets/enemy.png", "enemy", getRendrer());
	Load::Get()->loadimage("assets/Yenemy.png", "enemy1", getRendrer());
	Load::Get()->loadimage("assets/realbullet.png", "realbullet", getRendrer());
	Load::Get()->loadimage("assets/d.png", "dbullet", getRendrer());

	playercheck = new Player;
	GameVect.push_back(playercheck);
	GameVect.back()->load(new LoaderParams(680, 720, 52, 68, "redjet", 2));
	
	playerposition = &GameVect.back()->Getposition();

	EnemyManager::Instance()->load(new LoaderParams(0, 0, 35, 35, "enemy", 3));
	EnemyManager::Instance()->init();
	EnemyManager::Instance()->load(new LoaderParams(720, 40, 35, 35, "enemy1", 3));
	EnemyManager::Instance()->init();
	EnemyManager::Instance()->load(new LoaderParams(0, 80, 35, 35, "enemy1", 3));
	EnemyManager::Instance()->init();
	EnemyManager::Instance()->load(new LoaderParams(720, 120, 35, 35, "enemy1", 3));
	EnemyManager::Instance()->init();
	EnemyManager::Instance()->load(new LoaderParams(50, 160, 35, 35, "enemy1", 3));
	EnemyManager::Instance()->init();

	SDL_ShowCursor(SDL_DISABLE);
	
	

	
	

	
	return true;
}

void Game::update()
{
	collisionManager.CheckBulletEnemyollision();
	collisionManager.CheckPlayerEnemyCollision(playercheck);
	collisionManager.CheckBulletPlayerCollision(playercheck);
	BulletManager::Get()->updateBullets();
	for (int i = 0; i < GameVect.size(); i++)
	{
		GameVect[i]->update();
	}
	EnemyManager::Instance()->update();
	
}

void Game::rendrer()
{
	SDL_RenderClear(myrendrer);
	
	/*Load::Get()->drawFrame("bullet", 100, 100, 11, 11, 1, 1, myrendrer, SDL_FLIP_NONE);*/
	for (int i = 0; i < GameVect.size(); i++)
	{
		GameVect[i]->draw();
	}
	BulletManager::Get()->drawBullets();
	EnemyManager::Instance()->draw();
	SDL_RenderPresent(myrendrer);
}

void Game::clean()
{
	for (int i = 0; i < GameVect.size(); i++)
	{
		GameVect[i]->clean();
	}
	BulletManager::Get()->clearBullets();
	EnemyManager::Instance()->clean();
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(mywindow);
	SDL_DestroyRenderer(myrendrer);
	SDL_Quit();
}

void Game::events()
{
	TheInputHandler::Instance()->update();
	
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			{
				Gamerunning = false;
			}
			break;
		}
	}

}
