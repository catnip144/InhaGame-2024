#pragma once

// >> : DirectX 9 추가
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;
#define Safe_Release(p) {if(p) p->Release(); p = NULL;}
#define Safe_Delete(p) {if(p) delete p; p = NULL;}

// << : DirectX 9 추가

#define Synthesize(varType, varName, funName) \
	protected : varType varName ; \
	public : inline varType Get##funName(void) const {return varName ; }\
	public : inline void Set##funName(varType var) { varName = var; }

#define Synthesize_Pass_By_Ref(varType, varName, funName) \
	protected : varType varName ; \
	public : inline varType& Get##funName(void) {return varName ; }\
	public : inline void Set##funName(varType& var) { varName = var; }

#define Safe_Add_Ref(p) { if(p) p->AddRef(); }

#define Synthesize_Add_Ref(varType, varName, funName) \
	protected : varType varName ; \
	public : inline varType Get##funName(void) const {return varName ; }\
	public : inline void Set##funName(varType var) { \
					if ( varName != var ) { \
						Safe_Add_Ref(var) ; \
						Safe_Release(varName) ; \
						varName = var; \
					} \
				}


// >> : Singleton 매크로 \뒤에 공백 없게 해라
#define Singleton(class_name) \
			private : \
					class_name(void) ; \
					~class_name(void) ; \
			public : \
				static class_name* GetInstance() \
				{ \
					static class_name instance; \
					return &instance ; \
				}
// << : Singleton

// >> : User Define Texture

struct ST_PC_VERTEX
{
	D3DXVECTOR3 p;
	D3DCOLOR c;
	enum {FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE};
};

struct ST_PNT_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;
	D3DXVECTOR2 t;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };
};

struct ST_PT_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR2 t;
	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };
};

// << : User Define Texture



// >> : My Class
#include "cCamera.h"
#include "cGroup.h"
#include "cMtlTex.h"
#include "cObject.h"
#include "cObjectManager.h"
#include "cObjLoader.h"
#include "cTextureManager.h"
#include "cDeviceManager.h"
#include "cGrid.h"
#include "cGizmo.h"
#include "cCubePNT.h"
#include "cCubeNode.h"
#include "cCubePC.h"
#include "cCubeMan.h"
#include "cMainGame.h"

// << : My Class