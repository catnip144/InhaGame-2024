#pragma once

#define GUIDE_SPEED 2
#define GUIDE_OFFSET_X 16
#define GUIDE_OFFSET_Y 35

enum FacingDir
{
	DIR_D,
	DIR_LU,
	DIR_LD,
	DIR_L,
	DIR_R,
	DIR_RD,
	DIR_RU,
	DIR_U
};

class Guide
{
private:
	POINT pos;
	FacingDir dir;
	int curFrame;
	int speed;

public:
	bool isMoving;
	int pathIndex;

	Guide(POINT pos);
	void Draw(HDC hdc);
	void UpdateFrame();
	void SetFacingDir(int dx, int dy);
	void SetEnabled(bool isEnabled);
	void Move(POINT pos);
	void MoveAlongPath(vector<POINT>& inputPath);
};

extern Guide guide;