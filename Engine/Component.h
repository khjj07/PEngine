#pragma once
#include "Common.h"
class Component abstract{
public:
	Component();
	virtual void Start();
	virtual void Update(double dt);
	virtual void OnDestroy();
	virtual void OnEnable();
	virtual void OnDisable();
	virtual void OnCollisionEnter(CollisionResponse other);
	virtual void OnCollisionExit(CollisionResponse other);
	virtual void OnCollisionStay(CollisionResponse other);
private:

};