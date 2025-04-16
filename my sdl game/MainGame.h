#pragma once
#include "GameBase.h"
#include "texturemanager.h"
#include <iostream>
#include "LoaderParams.h"
#include "Vector2D.h"
#include<SDL.h>

class MainGame:public GameBase
{

public: 

	MainGame();

	virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void load(const LoaderParams* myparam);
    virtual Vector2D &Getposition(){ return myposition; }
    virtual bool   &GetDeadState(){ return isDead; }
    virtual void collision();


protected:

    Vector2D myposition;
    Vector2D myvelocity;
    Vector2D myacceleration;
    Vector2D Direction;
    int m_currentRow;
    int m_currentFrame;
    int m_width;
    int m_height;
    bool isDead=false;
    int m_callbackID;
    int m_animSpeed;
   
    std::string m_textureID;

    int m_numFrames;

};

