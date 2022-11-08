#include "MainCamera.h"
MainCamera::MainCamera()
{

}

MainCamera::MainCamera(Vector2 pos) :GameObject(pos)
{
	Camera *camera= new Camera(transform, 1);
	AddComponent(camera);
}