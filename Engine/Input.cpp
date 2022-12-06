#include "Input.h"

KeyStructure Input::Mouse[3] = {
	KeyStructure(VK_LBUTTON),
	KeyStructure(VK_RBUTTON),
	KeyStructure(VK_MBUTTON)
};
int Input::MouseWheel=1;
vector<int> Input::Pressed=vector<int>();
vector<int> Input::Released = vector<int>();

Vector2 Input::GetMousePosition()
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(Win32api::getWin()->m_hWnd, &p);
	return Camera::Main->GetPosition() + Vector2(p.x, p.y);
}

bool Input::GetMouseButton(int btn)
{
	if (GetAsyncKeyState(Mouse[btn].keyCode))
		return true;
	else
		return false;
}

bool Input::GetMouseButtonDown(int btn)
{
	if (Mouse[btn].pressed && GetAsyncKeyState(Mouse[btn].keyCode))
	{
		Mouse[btn].pressed = false;
		return true;
	}
	return false;
}

bool Input::GetMouseButtonUp(int btn)
{
	if (Mouse[btn].released && GetAsyncKeyState(Mouse[btn].keyCode))
	{
		Mouse[btn].released = false;
		return true;
	}
	return false;
}

int Input::GetMouseWheel()
{
	return MouseWheel;
}

bool Input::GetKeyDown(int key)
{
	vector<int>::iterator iter = Pressed.begin();
	for (; iter < Pressed.end(); iter++)
	{
		if ((*iter) == key)
		{
			Pressed.erase(std::remove_if(Pressed.begin(), Pressed.end(), [key](int x) { return x == key; }), Pressed.end());
			return true;
		}
	}
	return false;
}

bool Input::GetKeyUp(int key)
{
	vector<int>::iterator iter = Released.begin();
	for (; iter < Released.end(); iter++)
	{
		if ((*iter) == key)
		{
			Released.erase(std::remove_if(Released.begin(), Released.end(), [key](int x) { return x == key; }), Released.end());
			return true;
		}
	}
	return false;
}

bool Input::GetKey(int key)
{
	if (GetAsyncKeyState(key))
		return true;
	else
		return false;
}

void Input::KeyPressed(int key)
{
	Pressed.push_back(key);
	Released.erase(std::remove_if(Released.begin(), Released.end(), [key](int x) { return x == key; }), Released.end());
}

void Input::KeyReleased(int key)
{
	Released.push_back(key);
	Pressed.erase(std::remove_if(Pressed.begin(), Pressed.end(), [key](int x) { return x == key; }), Pressed.end());
}