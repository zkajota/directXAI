#pragma once
#include <vector>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <xnamath.h>

class camera
{
public:
	camera();
	~camera();

	XMMATRIX camView;
	XMMATRIX camProjection;

	XMVECTOR camPosition;
	XMVECTOR camTarget;
	XMVECTOR camUp;

	void CameraSetup(int width, int height);
	void CameraPosition(float a, float b, float c, float d);
	void CameraTarget(float a, float b, float c, float d);
	void CameraUp(float a, float b, float c, float d);

};

