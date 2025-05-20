#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

class MenuButton:public SDLGameObject
{
	int m_callbackID;
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	void (*m_callback)();
	bool m_bReleased;

public:
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
	void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};

class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};