#include "cGrid.h"
#include "cGizmo.h"
#include "framework.h"

cGrid::cGrid()
{
}

cGrid::~cGrid()
{
	for (auto p : m_vecGizmo)
	{
		Safe_Delete(p);
	}
	m_vecGizmo.clear();
}

void cGrid::Setup(int nNumHalfTile, float fInterval)
{
	float fMax = nNumHalfTile * fInterval;
	float fMin = -nNumHalfTile * fInterval;

	ST_PC_VERTEX v;

	for (int i = 1; i <= nNumHalfTile; ++i)
	{
		if (i % 5 == 0)
		{
			v.c = D3DCOLOR_XRGB(255, 255, 255);
		}
		else
		{
			v.c = D3DCOLOR_XRGB(128, 128, 128);
		}

		v.p = D3DXVECTOR3(fMin, 0,  i * fInterval); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0,  i * fInterval); m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(fMin, 0, -i * fInterval); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0, -i * fInterval); m_vecVertex.push_back(v);

		//세로
		v.p = D3DXVECTOR3(i * fInterval, 0, fMin); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(i * fInterval, 0, fMax); m_vecVertex.push_back(v);	

		v.p = D3DXVECTOR3(-i * fInterval, 0, fMin); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i * fInterval, 0, fMax); m_vecVertex.push_back(v);
	}

	//중심 선
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(fMin, 0, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0, 0); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(0, fMin, 0); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, fMax, 0); m_vecVertex.push_back(v);


	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(0, 0, fMin); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0, 0, fMax); m_vecVertex.push_back(v);

	// >> : Gizmo

	cGizmo* pGizmo = NULL;
	D3DXMATRIXA16 matR;

	// : x-coord
	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI / 2.0f);
	pGizmo->Setup(D3DCOLOR_XRGB(255, 0, 0), matR);
	m_vecGizmo.push_back(pGizmo);

	// : y-coord
	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI);
	pGizmo->Setup(D3DCOLOR_XRGB(0, 255, 0), matR);
	m_vecGizmo.push_back(pGizmo);

	// : z-coord
	pGizmo = new cGizmo;
	D3DXMatrixRotationX(&matR, D3DX_PI / 2.0f);
	pGizmo->Setup(D3DCOLOR_XRGB(0, 0, 255), matR);
	m_vecGizmo.push_back(pGizmo);

	// << : 

}

void cGrid::Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld); // 위에서 적용됬으니 여기서는 안해도 상관 없다...

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecVertex.size() / 2, &m_vecVertex[0], sizeof(ST_PC_VERTEX));

	for (auto p : m_vecGizmo)
	{
		p->Render();
	}

	//g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld); // 위에서 적용됬으니 여기서는 안해도 상관 없다...

	//g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	//g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecVertex.size() / 3, &m_vecVertex[0], sizeof(ST_PC_VERTEX));
}
