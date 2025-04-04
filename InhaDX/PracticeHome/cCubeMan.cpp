#include "framework.h"
#include "cCubeMan.h"
#include "cCubeNode.h"

#include "cBody.h"
#include "cHead.h"
#include "cLeftArm.h"
#include "cRightArm.h"
#include "cLeftLeg.h"
#include "cRightLeg.h"

cCubeMan::cCubeMan()
	: m_pRoot(NULL)
{
}

cCubeMan::~cCubeMan()
{
	if (m_pRoot)
	{
		m_pRoot->Destroy();
	}
}

void cCubeMan::Setup()
{
	cCharacter::Setup();

	ZeroMemory(&m_stMt1, sizeof(D3DMATERIAL9));
	m_stMt1.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMt1.Diffuse = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMt1.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	//D3DXCreateTextureFromFile(g_pD3DDevice, L"grass.jpg", &m_pTexture);

	cBody* pBody = new cBody;
	pBody->Setup();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->Setup();
	m_pRoot->AddChild(pHead);


	cLeftArm* pleftArm = new cLeftArm;
	pleftArm->Setup();
	pleftArm->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(pleftArm);

	cRightArm* prightArm = new cRightArm;
	prightArm->Setup();
	prightArm->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(prightArm);

	cLeftLeg* pLeftLeg = new cLeftLeg;
	pLeftLeg->Setup();
	pLeftLeg->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(pLeftLeg);

	cRightLeg* RrightLeg = new cRightLeg;
	RrightLeg->Setup();
	RrightLeg->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(RrightLeg);
}

void cCubeMan::Update()
{
	cCharacter::Update();

	if (m_pRoot)
	{
		m_pRoot->Update();
	}
}

void cCubeMan::Render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetMaterial(&m_stMt1);

		cCharacter::Render();

		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		if (m_pRoot)
		{
			m_pRoot->Render();
		}

		//��ǥ�� ���̰� �ҷ��� �� ����

		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	}
}
