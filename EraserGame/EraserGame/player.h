#pragma once

#define PLAYER_SIZE 10
#define PLAYER_SPEED 10

class Player
{
private:
	POINT pos;
	int speed;
	int radius;
	bool isDrawing = false;
	vector<POINT> path;
	void AdjustPosition();

public:
	void Init();
	void Draw(HDC& hdc);
	void DrawLine(HDC& hdc);

	void Move(int inputType);
	void Rollback();
	void SetIsDrawing(bool state);

	bool IsPressing();
	bool IsDrawing() { return isDrawing; }
	int GetRadius() { return radius; }
	vector<POINT>& GetPath() { return path; }
};
