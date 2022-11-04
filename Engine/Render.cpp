#include "Render.h"

Render::Render()
{

}
void Render::Init()
{

}

void Render::Update(HDC *hdc, Scene *currentScene)
{
	vector<GameObject*>::iterator obj = currentScene->gameObjectList.begin();
	for(; obj < currentScene->gameObjectList.end(); obj++)
	{
		(*obj)->render(hdc);
	}
}

void Render::Clear()
{

}