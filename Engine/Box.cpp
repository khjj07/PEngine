#include "Box.h"
Box::Box()
{

}

Box::Box(Vector2 pos):GameObject(pos)
{
	RectangleRenderer* renderer = new RectangleRenderer(transform, Vector4(0, 0, 255, 255), Vector4(0, 0, 255, 255));
	AddComponent(renderer);
}