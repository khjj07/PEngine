#include "Animation.h"


Animation::Animation(Renderer* r)
{
	renderer = r;
}
void Animation::Play(float duration, bool loop)
{
	if (!animationHandler)
	{
		animationHandler = Timer::Delay(duration / imageList.size(), true, [loop, this]() {
			static vector<HBITMAP>::iterator iter = imageList.begin();
			iter++;
			if (iter >= imageList.end())
			{
				if (!loop)
					Timer::Cancel(animationHandler);
				else
				{
					iter = imageList.begin();
					renderer->bmp = (*iter);
				}
					
			}
			else
			{
				renderer->bmp = (*iter);
			}
				
		});
	}
}
void Animation::Cancel()
{
	Timer::Cancel(animationHandler);
	animationHandler = nullptr;
}

void Animation::PushImage(int img)
{
	imageList.push_back((HBITMAP)LoadBitmap(Win32api::getWin()->m_hInstance, MAKEINTRESOURCE(img)));
}