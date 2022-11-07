#include "BoxScript.h"


BoxScript::BoxScript(Transform* t)
{
	transform = t;
}
void BoxScript::Start()
{
	static bool add = true;
	static bool check = true;

	Timer::Delay(0.05, true, [this]() {
		if (transform->scale.x > 1.5 && add)
			add = false;
		else if (transform->scale.x < 0.5 && !add)
			add = true;

		if (add)
		{
			transform->scale.x += 0.1;
			transform->scale.y += 0.1;
		}
		else
		{
			transform->scale.x -= 0.1;
			transform->scale.y -= 0.1;
		}
	});
	Timer::Delay(2, true, [this]() {
	

		if (check)
		{
			direction = Vector2(1, 0);
			check = false;
		}
		else
		{
			direction = Vector2(-1, 0);
			check = true;
		}
	});
}

void BoxScript::Update(double dt)
{
	velocity = direction * speed * dt;
	transform->rotation += speed * dt;
	transform->position += velocity;
}