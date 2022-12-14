#pragma once
#include "Common.h"
#include "Collider.h"
#include "Component.h"
#include "Transform.h"

class Transform;
class GameObject abstract{
public:
	GameObject();
	GameObject(Vector2 position);
	~GameObject();
	
	void Start();
	CollisionResponse Collide(Collider *other);
	void Update(double dt);
	void OnDestroy();
	void Destory();
	void Enable();
	void Disable();
	void OnEnable();
	void OnDisable();
	void AddComponent(Component*);
	void OnCollisionEnter(CollisionResponse response);
	void OnCollisionExit(CollisionResponse response);
	void OnCollisionStay(CollisionResponse response);
	template<typename T>
	T* GetComponent();
	Transform *transform;
	vector<Component*> componentList;
	vector<Component*> addComponentQueue;
	bool started = false;
	bool destroy = false;
private:
	vector<Component*>::iterator componentIter;
	bool isEnabled = true;
	bool awaked = false;
};

template<typename T>
T* GameObject::GetComponent()
{
	vector<Component*>::iterator component = componentList.begin();
	for (; component < componentList.end(); component++)
	{
		if (typeid(T).name() == typeid(**component).name())
			return (T*)*component;
	}
	return nullptr;
}

