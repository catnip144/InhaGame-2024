// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

using namespace std;

#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS 
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include "resource.h"
#include "commdlg.h"
#include <windows.h>
#include <TCHAR.h>
#include <vector>
#include <cmath>
#include <time.h>
#include <tchar.h>
#include <algorithm>

extern HBITMAP	hBgImage;
extern BITMAP	bitBg;

extern HBITMAP	hMultiplierItemImage;
extern BITMAP	bitMultiplierItem;

extern HBITMAP	hStickyItemImage;
extern BITMAP	bitStickyItem;

extern HBITMAP	hStretchItemImage;
extern BITMAP	bitStretchItem;

