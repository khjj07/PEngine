#pragma once
#include "Common.h"
#include "Win32api.h"
class Screen {
public:
	Screen(Vector2 res);
public:
	Vector2 resolution;
	RECT rt;
private:

};
