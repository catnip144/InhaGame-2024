#include "framework.h"

//class c

cMainGame::cMainGame() : m_pCubePC(NULL), m_pGrid(NULL), m_pCamera(NULL)
{
	srand(time(0));
}

cMainGame::~cMainGame()
{
	Safe_Delete(m_pCamera);
	Safe_Delete(m_pGrid);
	Safe_Delete(m_pCubePC);
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup_Line()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(0, 2, 0); m_vecLineVertex.push_back(v);
	v.p = D3DXVECTOR3(0, -2, 0); m_vecLineVertex.push_back(v);

}

void cMainGame::Setup_Triangle()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0); m_vecTrianleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0); m_vecTrianleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 0); m_vecTrianleVertex.push_back(v);
}

void cMainGame::Draw_Line()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecLineVertex.size() / 2, &m_vecLineVertex[0], sizeof(ST_PC_VERTEX));
}

void cMainGame::Draw_Triangle()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld); // 위에서 적용됬으니 여기서는 안해도 상관 없다...

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTrianleVertex.size() / 3, &m_vecTrianleVertex[0], sizeof(ST_PC_VERTEX));
}

void cMainGame::SetUp()
{
	Setup_Line();
	Setup_Triangle();

	m_pCubePC = new cCubePC;
	m_pCubePC->Setup();

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubePC->GetPosition());

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{/*
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXVECTOR3 vEye = D3DXVECTOR3(0, 0, -5.0f);
	D3DXVECTOR3 vLookAts = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 vUp = D3DXVECTOR3(0, 1, 0);

	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAts, &vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4.0F, ((float)rc.right / rc.bottom), 1.0F, 1000.0F);

	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);*/

	if (m_pCubePC)
	{
		m_pCubePC->Update();
	}
	if (m_pCamera)
	{
		m_pCamera->Update();
	}
}

void cMainGame::Render()
{
	
	//XRGB --> 알파값 안 씀
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 255, 255),
		1.0F, 0); //배경 지우는 역할을 수행함.

	//WM_Paint 같네
	g_pD3DDevice->BeginScene();

	Draw_Line();
	Draw_Triangle();

	if (m_pGrid)
		m_pGrid->Render();

	if (m_pCubePC)
		m_pCubePC->Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
	{
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
	}
}
