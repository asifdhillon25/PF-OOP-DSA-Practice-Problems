#include "Player.h"
#include "Game.h"
#include "InputHandler.h"
#include "BulletManager.h"
#include "SoundManager.h"
#include "TextManager.h"
Player::Player() :MainGame()
{
    
   
    
   
}



void Player::load(const LoaderParams* myparam)
{
    MainGame::load(myparam);
    Direction.m_y = -10;
   
}

void Player::draw()
{
    TextManager::Get()->renderText("ASIF DHILLON @%", 200, 200,28);
    MainGame::draw();
    
   
}



void Player::update()
{

   
    
     static bool mouseButtonPreviouslyPressed = false;

    if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
    {
        // Check if the mouse button was not previously pressed
        if (!mouseButtonPreviouslyPressed)
        {
            // Fire the bullet
            BulletManager::Get()->addPlayerbullet(myposition.getX() + 20, myposition.getY() - 18, 9, 19, "realbullet", 0,Direction);
            TheSoundManager::Instance()->playSound("shoot", 0);
            // Set the flag to true to indicate that the mouse button is now pressed
            mouseButtonPreviouslyPressed = true;

        }
    }
    else
    {
        // If the mouse button is not pressed, reset the flag
        mouseButtonPreviouslyPressed = false;
    }

    m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames) - 1);


    //// Adjust the speed factor for slower or faster movement
    //if (TheInputHandler::Instance()->isKeyDown(SDL_GetScancodeFromKey(SDLK_RIGHT)) && myposition.m_x<1280)
    //{
    //    myposition.m_x+=3;
    //    }
    //else if (TheInputHandler::Instance()->isKeyDown(SDL_GetScancodeFromKey(SDLK_LEFT)) && myposition.m_x > 0)
    //{
    //    myposition.m_x-= 3;
    //}
    //else if (TheInputHandler::Instance()->isKeyDown(SDL_GetScancodeFromKey(SDLK_UP))  &&myposition.m_y > 0)
    //{
    //    myposition.m_y-= 3;

    //}
    //else if (TheInputHandler::Instance()->isKeyDown(SDL_GetScancodeFromKey(SDLK_DOWN)) && myposition.m_y < 720  )
    //{
    //    myposition.m_y+= 3;
    //}


    
        Vector2D *TEMP= TheInputHandler::Instance()->getMousePosition();
        myposition=*TEMP;
        m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames ) );
       
    MainGame::update();

}

void Player::clean()
{
    Load::Get()->clearFromTextureMap(m_textureID);
}
