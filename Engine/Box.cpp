#include "Box.h"
Box::Box()
{

}

Box::Box(Vector2 pos):GameObject(pos)
{
	Renderer* renderer = new Renderer(transform);
	BoxScript* script = new BoxScript(transform);
	AddComponent(renderer);
	AddComponent(script);
}