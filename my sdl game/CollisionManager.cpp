#include "CollisionManager.h"

void CollisionManager::CheckPlayerEnemyCollision(Player* player)
{

   
    SDL_Rect* PlayerRect = new SDL_Rect;
    PlayerRect->x = player->Getposition().getX();
    PlayerRect->y = player->Getposition().getY();
    PlayerRect->h = player->GetHeight();
    PlayerRect->w = player->GetWidth();

    for (int i = 0;i<EnemyManager::Instance()->GetEnemy().size(); i++)
    {
        
        SDL_Rect* EnemyRect = new SDL_Rect;
        Enemy* CheckEnemy = EnemyManager::Instance()->GetEnemy()[i];
        EnemyRect->x = CheckEnemy->Getposition().getX();
        EnemyRect->y = CheckEnemy->Getposition().getY();
        EnemyRect->h = CheckEnemy->GetHeight();
        EnemyRect->w = CheckEnemy->GetWidth();

        if (RectRect(PlayerRect, EnemyRect))
        {
            
            CheckEnemy->collision();
            player->collision();
        }
        delete EnemyRect;
    }
    
    delete PlayerRect;
    
}

void CollisionManager::CheckBulletEnemyollision()
{

    for (int i = 0; i<BulletManager::Get()->GetBullet().size(); i++)
    {
        for (int j = 0; j<EnemyManager::Instance()->GetEnemy().size(); j++)
        {
            SDL_Rect* PlayerRect = new SDL_Rect;
            SDL_Rect* EnemyRect = new SDL_Rect;
            Bullet* CheckBullet = BulletManager::Get()->GetBullet()[i];
            PlayerRect->x = CheckBullet->Getposition().getX();
            PlayerRect->y = CheckBullet->Getposition().getY();
            PlayerRect->h = CheckBullet->GetHeight();
            PlayerRect->w = CheckBullet->GetWidth();

            Enemy* CheckEnemy = EnemyManager::Instance()->GetEnemy()[j];
            EnemyRect->x = CheckEnemy->Getposition().getX();
            EnemyRect->y = CheckEnemy->Getposition().getY();
            EnemyRect->h = CheckEnemy->GetHeight();
            EnemyRect->w = CheckEnemy->GetWidth();

            if (RectRect(PlayerRect, EnemyRect))
            {
                CheckEnemy->collision();
                CheckBullet->collision();
                
            }
            

            delete EnemyRect;
            delete PlayerRect;
        }
       
       

    }
}

void CollisionManager::CheckBulletPlayerCollision(Player* player)
{

    SDL_Rect* PlayerRect = new SDL_Rect;
    PlayerRect->x = player->Getposition().getX();
    PlayerRect->y = player->Getposition().getY();
    PlayerRect->h = player->GetHeight();
    PlayerRect->w = player->GetWidth();

    for (int i = 0; i < BulletManager::Get()->GetEnemyBullet().size(); i++)
    {

        SDL_Rect* BulletRect = new SDL_Rect;
        EnemyBullet* CheckBullet = BulletManager::Get()->GetEnemyBullet()[i];
        BulletRect->x = CheckBullet->Getposition().getX();
        BulletRect->y = CheckBullet->Getposition().getY();
        BulletRect->h = CheckBullet->GetHeight();
        BulletRect->w = CheckBullet->GetWidth();

        if (RectRect(PlayerRect, BulletRect))
        {

            CheckBullet->collision();
            player->collision();
        }
        delete BulletRect;
    }

    delete PlayerRect;

}
