#pragma once

class cCubePC;
class cGrid;
class cCamera;

class cMainGame
{

private:
	std::vector<ST_PC_VERTEX> m_vecLineVertex;
	std::vector<ST_PC_VERTEX> m_vecTrianleVertex;

	cCubePC* m_pCubePC;
	cGrid* m_pGrid;
	cCamera* m_pCamera;

public:
	cMainGame();
	~cMainGame();

public:
	void Setup_Line();
	void Setup_Triangle();

	void Draw_Line();
	void Draw_Triangle();

	void SetUp();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};


