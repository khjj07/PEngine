#include "BitmapRenderer.h"

HBITMAP GetRotatedBitmap(HDC hdc, HBITMAP hBitmap, int source_x, int source_y,
	int dest_width, int dest_height, float angle, COLORREF bkColor)
{
	HDC sourceDC = CreateCompatibleDC(hdc);										
	HDC destDC = CreateCompatibleDC(hdc);
	HBITMAP hbmResult = CreateCompatibleBitmap(hdc, dest_width, dest_height);

	HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, hBitmap);
	HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult);			
	HBRUSH hbrBack = CreateSolidBrush(bkColor);								
	HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack);						
	PatBlt(destDC, 0, 0, dest_width, dest_height, PATCOPY);							
	DeleteObject(SelectObject(destDC, hbrOld));

	angle = (float)(angle * PI / 180);									
	float cosine = (float)cos(angle);		
	float sine = (float)sin(angle);								

	SetGraphicsMode(destDC, GM_ADVANCED);										


	XFORM xform;																		
	xform.eM11 = cosine;																
	xform.eM12 = sine;																	
	xform.eM21 = -sine;																	
	xform.eM22 = cosine;																
	xform.eDx = (FLOAT)dest_width / 2.0f;												
	xform.eDy = (FLOAT)dest_height / 2.0f;												

	SetWorldTransform(destDC, &xform);
	BitBlt(destDC, -(dest_width / 2), -(dest_height / 2), dest_width, dest_height, sourceDC, source_x, source_y, SRCCOPY);


	SelectObject(sourceDC, hbmOldSource);
	SelectObject(destDC, hbmOldDest);
	DeleteObject(sourceDC);
	DeleteObject(destDC);
	return hbmResult;
}


BitmapRenderer::BitmapRenderer(Transform* t,int img)
{
	transform = t;
	image = img;
	bmp = (HBITMAP)LoadBitmap(Win32api::getWin()->m_hInstance, MAKEINTRESOURCE(image));
}
void BitmapRenderer::Update(double dt)
{
    Draw();
}
void BitmapRenderer::Draw()
{
	static HDC tmp;

	HBITMAP hTempBitmap, hOldBitmap;
    Render* render = Render::Instance();
	tmp = CreateCompatibleDC(render->hdc);
    GetObject(bmp, sizeof(BITMAP), &(btSize));

	hTempBitmap = GetRotatedBitmap(render->hdc, bmp, 0,0,btSize.bmWidth, btSize.bmHeight, transform->rotation, RGB(255, 255, 255));

	hOldBitmap = (HBITMAP)SelectObject(tmp, hTempBitmap);
	int pos_x = transform->position.x - btSize.bmWidth / 2 * transform->scale.x;
	int pos_y = transform->position.y - btSize.bmHeight / 2 * transform->scale.y;
	int size_x = btSize.bmWidth * transform->scale.x / Camera::Main->transform->scale.x;
	int size_y = btSize.bmHeight * transform->scale.y / Camera::Main->transform->scale.y;
	StretchBlt(render->MemDC, pos_x, pos_y, size_x, size_y, tmp, 0,0, btSize.bmWidth , btSize.bmHeight, SRCCOPY);
	SelectObject(tmp, hOldBitmap);
	DeleteObject(hTempBitmap);
    DeleteDC(tmp);
}