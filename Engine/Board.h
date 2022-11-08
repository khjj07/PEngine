#pragma once
#include "Common.h"
#include "GameObject.h"
#include "LineRenderer.h"
#include "BoardScript.h"
#include "PointStone.h"
#include "PointStoneScript.h"
#include "BitmapRenderer.h"
#include "Stone.h"
class Stone;
class PointStone;
struct Cell
{
	Vector2 position;
	Stone* stone = nullptr;
	COLORREF color;
	bool check=false;
	Cell* Up;
	Cell* Down;
	Cell* Left;
	Cell* Right;
};

class Board : public GameObject
{
public:
	Board();
	Board(Vector2 pos, PointStone* stone);
private:

};
