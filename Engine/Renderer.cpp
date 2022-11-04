#include "Renderer.h"

Renderer::Renderer(Transform* t)
{
	transform = t;
	Engine::Instance()->render->buffer.push_back(this);
}

void Renderer::Draw(HDC* hdc)
{

}