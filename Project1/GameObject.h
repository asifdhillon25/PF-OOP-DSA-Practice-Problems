#pragma once

#include<SDL.h>
#include <SDL_image.h>
#include <iostream>
#include<map>

#include "LoaderParams.h"


using namespace std;


class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	// new load function 
	virtual void load(const LoaderParams* pParams) = 0;
protected:
	GameObject() {}
	virtual ~GameObject() {}
};