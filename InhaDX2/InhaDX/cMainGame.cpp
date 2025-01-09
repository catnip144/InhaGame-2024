#include "framework.h"
#include "cMainGame.h"
#include "cCubePC.h"	
#include "cGrid.h"
#include "cCamera.h"
#include "cCubeMan.h"
#include "cObjLoader.h"
#include "cGroup.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL)
	, m_pGrid(NULL)
	, m_pCamera(NULL) 
	, m_pCubeMan(NULL)
	, m_pTexture(NULL)
{
	srand(time(0)); 
}

cMainGame::~cMainGame()
{
	for (auto p : m_vecGroup)
	{
		Safe_Release(p); 
	}
	m_vecGroup.clear(); 

	Safe_Release(m_pTexture); 
	Safe_Delete(m_pCamera); 
	Safe_Delete(m_pGrid);
	Safe_Delete(m_pCubePC); 
	Safe_Delete(m_pCubeMan); 
	g_pDeviceManager->Destroy(); 
	g_pObjectManager->Destroy(); 
	g_pTextureManager->Destroy(); 
}

void cMainGame::Setup_Line()
{
	ST_PC_VERTEX v; 
	v.c = D3DCOLOR_XRGB(255, 0, 0); 
	v.p = D3DXVECTOR3(0, 1, 0); m_vecLineVertex.push_back(v); 
	v.p = D3DXVECTOR3(0, -1, 0); m_vecLineVertex.push_back(v);

}

void cMainGame::Setup_Triangle()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f); m_vecTriangleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(-1.0f,  1.0f, 0.0f); m_vecTriangleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3( 1.0f,  1.0f, 0.0f); m_vecTriangleVertex.push_back(v);
}

void cMainGame::Setup_Texture()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, L"����.png", &m_pTexture); 
	ST_PT_VERTEX v; 
	v.p = D3DXVECTOR3(0, 0, 0); 
	v.t = D3DXVECTOR2(0, 1); 
	m_vecVertex.push_back(v); 

	v.p = D3DXVECTOR3(0, 2, 0);
	v.t = D3DXVECTOR2(0, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2, 2, 0);
	v.t = D3DXVECTOR2(1, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 0, 0);
	v.t = D3DXVECTOR2(0, 1);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2, 2, 0);
	v.t = D3DXVECTOR2(1, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2, 0, 0);
	v.t = D3DXVECTOR2(1, 1);
	m_vecVertex.push_back(v);



	// 
	v.p = D3DXVECTOR3(0, 0, 0);
	v.t = D3DXVECTOR2(0, 1);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-2, 2, 0);
	v.t = D3DXVECTOR2(1, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 2, 0);
	v.t = D3DXVECTOR2(0, 0);
	m_vecVertex.push_back(v);


}

void cMainGame::Setup_Obj()
{
	cObjLoader loader; 
	loader.Load(m_vecGroup, (char*)"obj", (char*)"box.obj"); 
}

void cMainGame::Draw_Line()
{
	D3DXMATRIXA16 matWorld; 
	D3DXMatrixIdentity(&matWorld); 
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld); 

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF); 
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST ,
		m_vecLineVertex.size() / 2 ,
		&m_vecLineVertex[0], 
		sizeof(ST_PC_VERTEX)); 
}

void cMainGame::Draw_Triangle()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecTriangleVertex.size() / 3,
		&m_vecTriangleVertex[0],
		sizeof(ST_PC_VERTEX));

}

void cMainGame::Draw_Texture()
{
	//g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); 
	//g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false); 
	D3DXMATRIXA16 matWorld; 
	D3DXMatrixIdentity(&matWorld); 
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	
	g_pD3DDevice->SetTexture(0, m_pTexture); 
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF); 
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PT_VERTEX)
		); 
	g_pD3DDevice->SetTexture(0, NULL);

	//g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}

void cMainGame::Draw_Obj()
{
	D3DXMATRIXA16 matWorld, matS, matR; 
	D3DXMatrixScaling(&matS, 0.1f, 0.1f, 0.1f); 
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0F); 
	matWorld = matS * matR; 

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld); 
	for (auto p : m_vecGroup)
	{
		p->Render(); 
	}
}

void cMainGame::Setup()
{
	Setup_Line(); 
	Setup_Triangle(); 
	Setup_Texture(); 
	Setup_Obj(); 

	m_pCubePC = new cCubePC; 
	m_pCubePC->Setup(); 

	m_pCubeMan = new cCubeMan; 
	m_pCubeMan->Setup(); 

	m_pGrid = new cGrid; 
	m_pGrid->Setup(); 

	m_pCamera = new cCamera; 
	//m_pCamera->Setup(&m_pCubePC->GetPosition()); 
	m_pCamera->Setup(&m_pCubeMan->GetPosition());

	Setup_Light(); 


	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false); 
}

void cMainGame::Update()
{
	if (m_pCubePC)
		m_pCubePC->Update(); 

	if (m_pCubeMan)
		m_pCubeMan->Update(); 

	if (m_pCamera)
		m_pCamera->Update(); 
}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(127,127,127),
		1.0F, 0); 

	g_pD3DDevice->BeginScene(); 

	//Draw_Line(); 
	//Draw_Triangle(); 
	//Draw_Texture(); 
	Draw_Obj(); 

	if (m_pGrid)
		m_pGrid->Render(); 

	//if (m_pCubePC)
	//	m_pCubePC->Render(); 

	if (m_pCubeMan)
		m_pCubeMan->Render(); 
	g_pD3DDevice->EndScene(); 

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL); 



}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam); 

}

void cMainGame::Setup_Light()
{
	D3DLIGHT9		stLight; 
	ZeroMemory(&stLight, sizeof(D3DLIGHT9)); 

	stLight.Type = D3DLIGHT_DIRECTIONAL; 
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f); 
	stLight.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);

	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f); 
	D3DXVec3Normalize(&vDir, &vDir); 
	stLight.Direction = vDir; 

	g_pD3DDevice->SetLight(0, &stLight); 
	g_pD3DDevice->LightEnable(0, true); 
}
