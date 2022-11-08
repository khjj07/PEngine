#include "PointStone.h"
PointStone::PointStone()
{

}

PointStone::PointStone(Vector2 pos) :GameObject(pos)
{
	CircleRenderer* renderer = new CircleRenderer(transform, 20, RGB(0, 0, 0), RGB(0, 0, 0));
	PointStoneScript* script = new PointStoneScript(transform);
	AddComponent(renderer);
	AddComponent(script);
}