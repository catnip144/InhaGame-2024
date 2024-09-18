#pragma once

#include <vector>
#include <cmath>
#include <queue>
#include "framework.h"
#include "graphic_control.h"

using namespace std;

#define TIMER_ID 1
#define TIMER_ANI 2

#define TIMER_ID_INTERVAL 45
#define TIMER_ANI_INTERVAL 140

#define PLAYER_SIZE 10
#define PLAYER_SPEED 10

class Player
{
private:
	POINT pos;
	int speed;
	int radius;
	vector<POINT> path;
	void AdjustPosition();

public:
	void Init();
	void Draw(HDC& hdc);
	void DrawLine(HDC& hdc);
	bool IsDrawing();
	void Move(int inputType);
	void Rollback();
	int GetRadius() { return radius; }
	vector<POINT>& GetPath() { return path; }
};

extern HWND g_hWnd;
extern HDC g_hdc, g_backMemDC;

extern Player player;
extern POINT playerStartPos;
extern POINT entryPos;

extern vector<vector<bool>> visited;
extern vector<MaskPolygon*> masks;

void DrawMap(HDC& hdc);
void DrawMasks(HDC& hdc);
void CreateVisitedGrid();
void CreateMask(vector<POINT>& path);
void FillOccupiedArea(vector<POINT>& path);
int GetUserInput();