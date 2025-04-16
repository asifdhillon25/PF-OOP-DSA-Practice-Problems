#pragma once
#include <string>

#include "LoaderParams.h"
class GameBase
{

public:

	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean() = 0;
	virtual void load(const LoaderParams* myparam) = 0;

	GameBase() {}
	virtual ~GameBase() {}
};

