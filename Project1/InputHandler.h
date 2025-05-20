#pragma once
#include <vector>
#include "SDL.h"
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void mouseupdate();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	Vector2D getMousePosition()
	{
		
		return m_mousePosition;
	}
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

private:

	InputHandler();

	Vector2D m_mousePosition;


	std::vector <bool> m_mouseButtonStates;

	~InputHandler() {}

	static InputHandler* s_pInstance;
	const Uint8* m_keystate;
	
};
typedef InputHandler TheInputHandler;

