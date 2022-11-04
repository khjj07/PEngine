#pragma once
#include "Common.h"
#include "GameObject.h"

class Scene abstract{
public:
	Scene();
	~Scene();
	void Start();
	void Collide();
	void Update(double dt);
	void Push(GameObject* newObject);
	void Pop(GameObject* newObject);
	void OnEnable();
	void OnDisable();
	vector<GameObject*> gameObjectList;

private:
	vector<GameObject*>::iterator objectIter;

};

