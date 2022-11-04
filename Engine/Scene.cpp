#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Start()
{
	objectIter = gameObjectList.begin();
	for (; objectIter < gameObjectList.end(); objectIter++)
	{
		if((*objectIter)->started)
			(*objectIter)->Start();
	}
}

void Scene::Collide()
{
	objectIter = gameObjectList.begin();
	for (; objectIter < gameObjectList.end(); objectIter++)
	{
		if ((*objectIter)->GetComponent<Collider>())
		{
			vector<GameObject*>::iterator otherIter = gameObjectList.begin();		
			for (; otherIter < gameObjectList.end(); otherIter++)
			{
				if ((*otherIter)->GetComponent<Collider>() && (*objectIter) != (*otherIter))
					(* objectIter)->Collide((*otherIter)->GetComponent<Collider>());
			}

		}
	}
}

void Scene::Update(double dt)
{
	objectIter = gameObjectList.begin();
	for (; objectIter < gameObjectList.end(); objectIter++)
		(*objectIter)->Update(dt);
}
void Scene::Push(GameObject* newObject)
{
	gameObjectList.push_back(newObject);
}

void Scene::Pop(GameObject* newObject)
{
	gameObjectList.erase(std::remove_if(gameObjectList.begin(), gameObjectList.end(), [newObject](GameObject* x) { return x == newObject; }), gameObjectList.end());
}

void Scene::OnEnable()
{
	objectIter = gameObjectList.begin();
	for (; objectIter < gameObjectList.end(); objectIter++)
		(*objectIter)->Enable();
}

void Scene::OnDisable()
{
	objectIter = gameObjectList.begin();
	for (; objectIter < gameObjectList.end(); objectIter++)
		(*objectIter)->Disable();
}