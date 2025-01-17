#include "framework.h"
#include "cFrustum.h"

cFrustum::cFrustum()
{
}

cFrustum::~cFrustum()
{
	// : near
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, -1, 0));
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, 1, 0));
	m_vecProjVertex.push_back(D3DXVECTOR3(1, 1, 0));
	m_vecProjVertex.push_back(D3DXVECTOR3(1, -1, 0));

	// : far
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, -1, 1));
	m_vecProjVertex.push_back(D3DXVECTOR3(-1, 1, 1));
	m_vecProjVertex.push_back(D3DXVECTOR3(1, 1, 1));
	m_vecProjVertex.push_back(D3DXVECTOR3(1, -1, 1));

	m_vecPlane.resize(6);
	m_vecPlane.resize(8);
}

void cFrustum::Setup()
{
}

void cFrustum::Update()
{
	D3DXMATRIXA16 matView, matProj;
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProj);
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matProj);

	for (size_t i = 0; i < m_vecProjVertex.size(); ++i)
	{
		D3DXVec3Unproject(&m_vecWorldVertex[i],
			&m_vecProjVertex[i],
			NULL,
			&matProj, &matView, NULL
		);
	}

	// : near
	D3DXPlaneFromPoints(&m_vecPlane[0],
		&m_vecWorldVertex[0],
		&m_vecWorldVertex[1],
		&m_vecWorldVertex[2]);

	// : far
	D3DXPlaneFromPoints(&m_vecPlane[1],
		&m_vecWorldVertex[6],
		&m_vecWorldVertex[5],
		&m_vecWorldVertex[4]);

	// : top
	D3DXPlaneFromPoints(&m_vecPlane[2],
		&m_vecWorldVertex[1],
		&m_vecWorldVertex[5],
		&m_vecWorldVertex[6]);

	// : bot
	D3DXPlaneFromPoints(&m_vecPlane[3],
		&m_vecWorldVertex[0],
		&m_vecWorldVertex[3],
		&m_vecWorldVertex[7]);

	// : left
	D3DXPlaneFromPoints(&m_vecPlane[4],
		&m_vecWorldVertex[1],
		&m_vecWorldVertex[0],
		&m_vecWorldVertex[4]);

	// : right
	D3DXPlaneFromPoints(&m_vecPlane[5],
		&m_vecWorldVertex[2],
		&m_vecWorldVertex[6],
		&m_vecWorldVertex[7]);
}

bool cFrustum::IsIn(ST_SPHERE* pSphere)
{
	for (D3DXPLANE p : m_vecPlane)
	{
		if (D3DXPlaneDotCoord(&p, &pSphere->vCenter) > pSphere->fRadius)
			return false;
	}
	return true;
}
