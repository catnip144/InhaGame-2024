#include "framework.h"
#include "cTextureManager.h"

LPDIRECT3DTEXTURE9 cTextureManager::GetTexture(char& szFullPath)
{
	return LPDIRECT3DTEXTURE9();
}

LPDIRECT3DTEXTURE9 cTextureManager::GetTexture(std::string& szFullPath)
{
	return LPDIRECT3DTEXTURE9();
}

void cTextureManager::Destroy()
{
}
