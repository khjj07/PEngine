#pragma once
#include "Common.h"
#include "Win32api.h"
struct KeyStructure {
	int keyCode;
	bool pressed = false;
	bool released = false;
	KeyStructure(int key)
	{
		keyCode = key;
	}
};

class Input
{
public:
	static Vector2 GetMousePosition();
	static bool GetMouseButton(int btn);
	static bool GetMouseButtonDown(int btn);
	static bool GetMouseButtonUp(int btn);
	static int GetMouseWheel();
	static bool GetKeyDown(int key);
	static bool GetKeyUp(int key);
	static bool GetKey(int key);
	static void KeyPressed(int key);
	static void KeyReleased(int key);
	static vector<int> Pressed;
	static vector<int> Released;
	static KeyStructure Mouse[3];
	static int MouseWheel;

};