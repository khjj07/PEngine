#pragma once
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <functional>
#include "Singleton.h"
#include "Color.h"
#include "framework.h"
#include "WinMain.h"
#include "Input.h"
using namespace std;

static enum CollisionState
{
	Enter,
	Exit,
	Stay,
	Not
};

class Collider;
struct CollisionResponse
{
	CollisionState state;
	Collider* other;
	CollisionResponse()
	{
		state = CollisionState::Not;
		other = nullptr;
	}
};
struct Vector4
{
	float x;
	float y;
	float z;
	float w;
	Vector4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	Vector4(float a, float b,float c,float d)
	{
		x = a;
		y = b;
		z = c;
		w = d;
	}
	COLORREF Rgb()
	{
		return RGB(x, y, z);
	}
};

struct Vector2
{
	float x;
	float y;
	Vector2()
	{
		x = 0;
		y = 0;
	}
	Vector2(float a,float b)
	{
		x = a;
		y = b;
	}
	Vector2 operator +(Vector2 k)
	{
		Vector2 result;
		result.x = x + k.x;
		result.y = y + k.y;
		return result;
	}

	Vector2 operator -(Vector2 k)
	{
		Vector2 result;
		result.x = x - k.x;
		result.y = y - k.y;
		return result;
	}

	Vector2 operator -=(Vector2 k)
	{
		Vector2 result;
		result.x = x - k.x;
		result.y = y - k.y;
		return result;
	}

	Vector2 operator *(float k)
	{
		Vector2 result;
		result.x = x * k;
		result.y = y * k;
		return result;
	}

	Vector2 operator /(float k)
	{
		Vector2 result;
		result.x = x / k;
		result.y = y / k;
		return result;
	}
};

struct Rect2D
{
	Vector2 min;
	Vector2 max;
	Rect2D()
	{
		min = Vector2();
		max = Vector2();
	}
	Rect2D(Vector2 a)
	{
		min = Vector2();
		max = a;
	}
	Rect2D(Vector2 a,Vector2 b)
	{
		min = a;
		max = b;
	}
	Rect2D operator +(Vector2 k)
	{
		Rect2D result;
		result.min.x = min.x + k.x;
		result.min.y = min.y + k.y;
		result.max.x = max.x + k.x;
		result.max.y = max.y + k.y;
		return result;
	}

	Rect2D operator -(Vector2 k)
	{
		Rect2D result;
		result.min.x = min.x - k.x;
		result.min.y = min.y - k.y;
		result.max.x = max.x - k.x;
		result.max.y = max.y - k.y;
		return result;
	}

};