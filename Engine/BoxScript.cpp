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
	Animation* anim1 = new Animation(transform->GetComponent<Renderer>());
	anim1->PushImage(IDB_BITMAP1);
	anim1->PushImage(IDB_BITMAP2);
	anim1->Play(1, true);
}

void BoxScript::Update(double dt)
{
	velocity = direction * speed * dt;
	transform->rotation += speed * dt;
	transform->position += velocity;
}