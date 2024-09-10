#pragma once

#include <vector>
#include <cmath>
#include "framework.h"
#include "graphic_control.h"

using namespace std;

#define TIMER_ID 1
#define TIMER_ANI 2

#define TIMER_ID_INTERVAL 1
#define TIMER_ANI_INTERVAL 140

#define PLAYER_SIZE 10
#define PLAYER_SPEED 10

class Player
{
private:
	POINT pos;
	int speed;
	int radius;
	int pathIndex = 0;
	vector<POINT> path;
	void AdjustPosition();

public:
	int GetRadius() { return radius; }
	void Init();
	void Draw(HDC& hdc);
	void DrawLine(HDC& hdc);
	void Move(WPARAM& wParam);
	vector<POINT>& GetPath() { return path; }
};

extern HWND g_hWnd;
extern HDC g_hdc, g_backMemDC;

extern Player player;
extern POINT playerStartPos;

extern vector<vector<pair<bool, int>>> visited;
extern vector<MaskPolygon*> masks;

void DrawMap(HDC& hdc);
void DrawMasks(HDC& hdc);
void CreateVisitedGrid();