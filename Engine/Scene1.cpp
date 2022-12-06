#include "Scene1.h"

Scene1::Scene1()
{
	PointStone* pointStone = new PointStone(Vector2(0, 0));
	Board* board = new Board(Vector2(-300, -300), pointStone);
	MainCamera* cam = new MainCamera(Vector2(0,300));
	Push(board);
	Push(pointStone);
	Push(cam);
}

Scene1::~Scene1()
{
}