#include "framework.h"
#include "cMainGame.h"

cMainGame::cMainGame() : m_pD3D(NULL) , m_pD3DDevice(NULL)
{

}

cMainGame::~cMainGame()
{
	Safe_Release(m_pD3DDevice);
	Safe_Release(m_pD3D);
}

void cMainGame::Setup()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	D3DCAPS9	stCaps;
	int			nVertexProcessing;

	// D3DDEVTYPE_HAL : 하드웨어 가속
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &stCaps);

	if (stCaps.DevCaps && D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}


	D3DPRESENT_PARAMETERS stD3Dpp;
	ZeroMemory(&stD3Dpp, sizeof(D3DPRESENT_PARAMETERS));

	stD3Dpp.SwapEffect				= D3DSWAPEFFECT_DISCARD;
	stD3Dpp.Windowed				= TRUE;
	stD3Dpp.BackBufferFormat		= D3DFMT_UNKNOWN;
	stD3Dpp.EnableAutoDepthStencil	= TRUE;
	stD3Dpp.AutoDepthStencilFormat	= D3DFMT_D16;

	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertexProcessing,
		&stD3Dpp,
		&m_pD3DDevice
	);
}

void cMainGame::Update()
{

}

void cMainGame::Render()
{
	m_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(45, 120, 127),
		1.0F,
		0
	);

	m_pD3DDevice->BeginScene();


	m_pD3DDevice->EndScene();


	m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
