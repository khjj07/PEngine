#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform();
}

GameObject::GameObject(Vector2 pos)
{
	transform = new Transform(pos);
}

GameObject::~GameObject()
{

}

void GameObject::Start()
{
	if (isEnabled)
	{
		componentIter = componentList.begin();
		for (; componentIter < componentList.end(); componentIter++)
			(*componentIter)->Init();
	}
}
CollisionResponse GameObject::Collide(Collider* other)
{
	CollisionResponse result;
	if (isEnabled && other->gameObject->isEnabled)
	{
		result = GetComponent<Collider>()->Collide(other);
		if (result.state == CollisionState::Enter)
			OnCollisionEnter(result);
		else if (result.state == CollisionState::Exit)
			OnCollisionExit(result);
		else if (result.state == CollisionState::Stay)
			OnCollisionStay(result);
	}
	return result;
}

void  GameObject::Update(double dt)
{
	if (isEnabled)
	{
		componentIter = componentList.begin();
		for (; componentIter < componentList.end(); componentIter++)
			(*componentIter)->Update(dt);
	}
	
}

void GameObject::OnCollisionEnter(CollisionResponse response)
{
	if (isEnabled)
	{
		componentIter = componentList.begin();
		for (; componentIter < componentList.end(); componentIter++)
			(*componentIter)->OnCollisionEnter(response);
	}
}

void GameObject::OnCollisionExit(CollisionResponse response)
{
	if (isEnabled)
	{
		componentIter = componentList.begin();
		for (; componentIter < componentList.end(); componentIter++)
			(*componentIter)->OnCollisionExit(response);
	}
}

void GameObject::OnCollisionStay(CollisionResponse response)
{
	if (isEnabled)
	{
		componentIter = componentList.begin();
		for (; componentIter < componentList.end(); componentIter++)
			(*componentIter)->OnCollisionStay(response);
	}
}

void GameObject::render(HDC * hdc)
{
	GetComponent<Renderer>()->Draw(hdc);
}

void GameObject::OnDestroy()
{
	componentIter = componentList.begin();
	for (; componentIter < componentList.end(); componentIter++)
		(*componentIter)->OnDestroy();
}

void GameObject::Destory()
{
	destroy = true;
}

void GameObject::Enable()
{
	if (!isEnabled)
	{
		isEnabled = true;
		OnEnable();
	}
}

void GameObject::Disable()
{
	if (isEnabled)
	{
		isEnabled = false;
		OnDisable();
	}
}

void GameObject::OnEnable()
{
	componentIter = componentList.begin();
	for (; componentIter < componentList.end(); componentIter++)
		(*componentIter)->OnEnable();
}

void GameObject::OnDisable() 
{
	componentIter = componentList.begin();
	for (; componentIter < componentList.end(); componentIter++)
		(*componentIter)->OnDisable();
}

void GameObject::AddComponent(Component* newComponent)
{
	componentList.push_back(newComponent);
}