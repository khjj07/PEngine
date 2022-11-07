#include "Scene1.h"

Scene1::Scene1()
{
	Box *box1 = new Box(Vector2(800,500));
	Push(box1);
}

Scene1::~Scene1()
{
}