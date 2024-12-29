#pragma once
class cGrid
{
public:
	cGrid();
	~cGrid();

private : 
	std::vector<ST_PC_VERTEX>	m_vecVertex;

public:
	void Setup(int nNumHalfTile = 15, float fInterval = 1.0f);
	void Render();

};

