#include "Stone.h"
Stone::Stone()
{

}

Stone::Stone(Vector2 pos,COLORREF color):GameObject(pos)
{
	CircleRenderer* renderer = new CircleRenderer(transform,20,RGB(0,0,0), color);
	AddComponent(renderer);
}