#include "framework.h"

cCubeNode::cCubeNode()
	: m_fRotDeltaX(0.0F)
	, m_pParentWorldTM(NULL)
	, m_vLocalPos(0, 0, 0)
	, m_fRotX(0.0f)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);

}

cCubeNode::~cCubeNode()
{
}

void cCubeNode::AddChild(cCubeNode* pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM; //내꺼에 대한 WorldTM
	m_vecChild.push_back(pChild);
}

void cCubeNode::Destroy()
{
	for (auto p : m_vecChild)
	{
		p->Destroy();
	}
	delete this;
}

void cCubeNode::Setup()
{
	cCubePNT::Setup();//기본 박스 생성
}

void cCubeNode::Update()
{
	cCubePNT::Update();

	{
		m_fRotX += m_fRotDeltaX;

		if (m_fRotX > D3DX_PI / 6.0f)
		{
			m_fRotX = D3DX_PI / 6.0f;
			m_fRotDeltaX *= -1;
		}

		if (m_fRotX < -D3DX_PI / 6.0f)
		{
			m_fRotX = -D3DX_PI / 6.0f;
			m_fRotDeltaX *= -1;
		}
	}

	//없어서 여기서 함
	D3DXMATRIXA16	matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixRotationX(&matR, m_fRotX);
	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	// : S x R x T ... T R S

	m_matLocalTM = matR * matT;
	m_matWorldTM = m_matLocalTM;

	if (m_pParentWorldTM)
		m_matWorldTM *= *m_pParentWorldTM;

	for (auto p : m_vecChild)
	{
		p->Update();
	}
}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);

	cCubePNT::Render();

	for (auto p : m_vecChild)
	{
		p->Render();
	}
}
