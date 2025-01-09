#pragma once

class cCubePC; 
class cGrid; 
class cCamera; 
class cCubeMan; 
class cGroup; 

class cMainGame
{

private : 
	std::vector<ST_PC_VERTEX> m_vecLineVertex; 
	std::vector<ST_PC_VERTEX> m_vecTriangleVertex; 


	cCubePC* m_pCubePC; 
	cCubeMan* m_pCubeMan; 

	std::vector<cGroup*>	m_vecGroup; 

	cGrid* m_pGrid; 
	cCamera* m_pCamera; 


	LPDIRECT3DTEXTURE9		m_pTexture; 
	std::vector<ST_PT_VERTEX>	m_vecVertex; 

public :
	cMainGame(); 
	~cMainGame(); 



public :
	void Setup_Line(); 
	void Setup_Triangle(); 
	void Setup_Texture(); 
	void Setup_Obj(); 

	void Draw_Line(); 
	void Draw_Triangle(); 
	void Draw_Texture(); 
	void Draw_Obj(); 

	void Setup();
	void Update(); 
	void Render(); 

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Setup_Light(); 

};

