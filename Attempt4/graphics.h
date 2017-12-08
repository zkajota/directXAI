#pragma once
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <memory>
#include <xnamath.h>
#include <vector>

#include "camera.h"

static D3D11_INPUT_ELEMENT_DESC layout[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
};

class graphics
{
public:
	graphics();
	~graphics();

	std::unique_ptr<camera> m_Camera;

	bool CreateSwapChain(int width, int height, HWND hwnd);
	void CleanUp();
	bool CreateGraphics(int width, int height);
	void draw();
	void initObjects();
	void update();
	
	struct Vertex
	{
		Vertex() {}
		Vertex(float x, float y, float z,
			float cr, float cg, float cb, float ca)
			: pos(x, y, z), color(cr, cg, cb, ca) {}

		XMFLOAT3 pos;
		XMFLOAT4 color;
	};

	struct cbPerObject
	{
		XMMATRIX  WVP;
	};

	cbPerObject cbPerObj;

	UINT numElements = ARRAYSIZE(layout);

	HRESULT hr;
	ID3D11Device* d3d11Device;
	IDXGISwapChain* SwapChain;
	ID3D11DeviceContext* d3d11DevCon;
	ID3D11RenderTargetView* renderTargetView;
	ID3D11Buffer* squareIndexBuffer;
	ID3D11DepthStencilView* depthStencilView;
	ID3D11Texture2D* depthStencilBuffer;
	ID3D11Buffer* squareVertBuffer;
	ID3D11VertexShader* VS;
	ID3D11PixelShader* PS;
	ID3D10Blob* VS_Buffer;
	ID3D10Blob* PS_Buffer;
	ID3D11InputLayout* vertLayout;
	ID3D11Buffer* cbPerObjectBuffer;

	static const int objectNumber = 10000;
	const float spaceBetween = 3.0f;
	float oldSpaceBetween = 0.0f;
	float x = 0.0f;
	
	XMMATRIX WVP;
	XMMATRIX cubeWorlds[objectNumber];
	XMMATRIX Translations[objectNumber];

	XMMATRIX cube1World;
	XMMATRIX cube2World;
	XMMATRIX Rotation;
	XMMATRIX Scale;
	XMMATRIX Translation;
	XMMATRIX Translation2;

	float rot = 0.01f;

};

