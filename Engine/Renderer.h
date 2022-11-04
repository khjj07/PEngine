#pragma once
#include "Common.h"
#include "Transform.h"
#include "Component.h"
#include "Engine.h"

class Renderer abstract:public Component{
public:
	Renderer(Transform* transform);
	Transform* transform;
	virtual void Draw(HDC *hdc);
private:

};