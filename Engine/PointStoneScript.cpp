#include "PointStoneScript.h"


PointStoneScript::PointStoneScript(Transform* t)
{
	transform = t;
}
void PointStoneScript::Start()
{
	static bool add = true;
	static bool check = true;
}

void PointStoneScript::Update(double dt)
{
	if (!target)
	{
		Vector2 mousePos = Input::GetMousePosition();
		transform->position = mousePos;
	}
	else
	{
		transform->position = target->position;
		if (Input::GetMouseButtonDown(0))
		{
			target->stone=(Stone*)Instantiate(new Stone(target->position, currentColor));
			target->color = currentColor;

			if (currentColor == RGB(0, 0, 0))
			{
				currentColor = RGB(255, 255, 255);
			}
			else
			{
				currentColor = RGB(0, 0, 0);
			}
			transform->GetComponent<CircleRenderer>()->brushColor = currentColor;
			stoneCreateEvent();
		}
	}
	target = nullptr;
}