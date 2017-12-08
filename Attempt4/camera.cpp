#include "camera.h"



camera::camera()
{
}


camera::~camera()
{
}

void camera::CameraSetup(int width, int height)
{
	speed = 1.0f;
	CameraPosition(0.0f, 3.0f, -50.0f, 0.0f);
	CameraTarget(0.0f, 0.0f, 0.0f, 0.0f);
	CameraUp(0.0f, 1.0f, 0.0f, 0.0f);
	camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
	camProjection = XMMatrixPerspectiveFovLH(0.4f*3.14f, (float)width / height, 1.0f, 1000.0f);
}
void camera::CameraPosition(float a, float b, float c, float d)
{
	camPosition = XMVectorSet(a, b, c, d);
}

void camera::CameraTarget(float a, float b, float c, float d)
{
	camTarget = XMVectorSet(a, b, c, d);
}

void camera::CameraUp(float a, float b, float c, float d)
{
	camUp = XMVectorSet(a, b, c, d);
}

void camera::CameraUpdate()
{
	speed = speed + 0.5f;
	CameraPosition(speed, 3.0f, -50.0f, 0.0f);
	camView = XMMatrixLookAtLH(camPosition, camTarget, camUp);
}