#include "Board.h"
Board::Board()
{

}

Board::Board(Vector2 pos, PointStone* stone) :GameObject(pos)
{	
	BoardScript* script = new BoardScript(transform, stone->GetComponent<PointStoneScript>());
	AddComponent(script);
}