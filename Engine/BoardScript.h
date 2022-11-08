#pragma once
#include "Common.h"
#include "Component.h"
#include "Transform.h"
#include "Timer.h"
#include "Animation.h"
#include "LineRenderer.h"
#include "BitmapRenderer.h"
#include "Event.h"
#include "PointStoneScript.h"
struct Cell;
class PointStoneScript;
class BoardScript : public Component
{
public:
	BoardScript(Transform* t,PointStoneScript *p);
	virtual void Start();
	virtual void Update(double dt);
	void UpdateBoard();
	bool CheckDie(Cell* cell);
	void revertAll();
	void KillAllChecked();
	Vector2 direction;
	Vector2 velocity;
	Cell *cell[20][20];

	Transform* transform;
	PointStoneScript* stoneFactory;
	
	float speed = 200;
	float fraction = 0.1;
	
private:

};

