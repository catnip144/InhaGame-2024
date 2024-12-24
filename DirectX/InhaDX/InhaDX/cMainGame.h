#pragma once
class cMainGame
{
private:
	std::vector<ST_PC_VERTEX> m_vecLineVertex;
	std::vector<ST_PC_VERTEX> m_vecTriangleVertex;

public:
	cMainGame();
	~cMainGame();

public:
	void Setup_Line();
	void Setup_Triangle();

	void Draw_Line();
	void Draw_Triangle();

	void Setup();
	void Update();
	void Render();
};