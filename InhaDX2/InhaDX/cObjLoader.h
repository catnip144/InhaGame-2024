#pragma once


class cMtlTex; 
class cGroup; 

class cObjLoader
{
public :
	cObjLoader(); 
	~cObjLoader(); 

private :
	std::map<std::string, cMtlTex*> m_mapMtlTex; 

public :
	void Load(OUT std::vector<cGroup*>& vecGroup,
		IN char* szFolder, IN char* szFile); 

	void LoadMtlLib(char* szFolder, char* szFile); 

	void LoadSurface(OUT std::vector<D3DXVECTOR3>& vecSurface,
		IN char* szFolder, IN char* szFile, IN D3DXMATRIXA16* pmat = NULL);
};

