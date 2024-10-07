#pragma once
#include "cVector3.h"
#include "cMatrix.h"
#include "framework.h"

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	HDC			m_MemDC;
	HBITMAP		m_hOldBitmap, m_hBitmap;
	
	std::vector<cVector3>	m_vecVertex;
	std::vector<DWORD>		m_vecIndex;

	cMatrix					m_matWorld;
	cMatrix					m_matView;
	cMatrix					m_matProj;
	cMatrix					m_matViewport;

	// 카메라 위치
	cVector3				m_vEye;
	cVector3				m_vLookAt;
	cVector3				m_vUp;

	cVector3				m_vPosition;
	float					m_fBoxRotY;
	cVector3				m_vBoxDirection;

	// >> : grid : 움직임 시각적인 확인 용도
	std::vector<cVector3>	m_vecLineVertex;
	cVector3				m_vAxisXTextPosition;
	cVector3				m_vAxisZTextPosition;
	// << :

	// >> : mouse
	POINT					m_ptPrevMouse;
	bool					m_isLButtonDown;
	float					m_fCameraDistance;
	cVector3				m_vCamRotAngle;
	// << :

	float					m_fScale;

public:
	void Setup();
	void Update();
	void Render(HDC hdc);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	bool IsBackFace(cVector3& v1, cVector3& v2, cVector3& v3);

	void SetGrid();
	void DrawGrid();

	void Update_Rotation();
	void Update_Move();
	void Update_Scale();
};