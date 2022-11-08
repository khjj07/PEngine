#pragma once
#include "Common.h"
#include "Component.h"
#include "Transform.h"
#include "Timer.h"
#include "Animation.h"
#include "Board.h"
#include "CircleRenderer.h"
#include "Event.h"
struct Cell;
class PointStoneScript : public Component
{
public:
	PointStoneScript(Transform* t);
	virtual void Start();
	virtual void Update(double dt);
	Vector2 direction;
	Vector2 velocity;
	Transform* transform;
	float speed = 200;
	float fraction = 0.1;
	Cell* target;
	COLORREF currentColor = RGB(0, 0, 0);
	Event stoneCreateEvent{};
private:

};

