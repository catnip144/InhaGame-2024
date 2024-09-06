#pragma once
#include "framework.h"

#define TIMER_ID 1
#define TIMER_ANI 2
#define TIMER_INTERVAL 1

#define IMAGE_BG_PATH "images/Background.bmp"
#define IMAGE_ITEM_MULTIPLER_PATH "images/Item_Multiply.bmp"
#define IMAGE_ITEM_STICKY_PATH "images/Item_Sticky.bmp"
#define IMAGE_ITEM_STRETCH_PATH "images/Item_Stretch.bmp"

#define SCORE_FILE_PATH "data/score.txt"

#define UI_FONT_NAME "Bauhaus 93"

#define MAX_BLOCK_HP 3
#define BLOCK_ROW 3
#define BLOCK_COL 10
#define OFFSET_X 10
#define OFFSET_Y 8

#define BALL_SIZE 10
#define BALL_SPEED 10
#define PI 3.141592

#define DIR_X cos((45 * PI / 180.0));
#define DIR_Y -sin((45 * PI / 180.0));

#define PADDLE_START_Y 9
#define PADDLE_WIDTH 110
#define PADDLE_HEIGHT 10
#define PADDLE_SPEED 40
#define PADDLE_STRETCH 15

#define ITEM_MAX_TYPE 3
#define ITEM_SPRITE_COL 4
#define ITEM_IMAGE_SIZE 2
#define ITEM_FALL_SPEED 3

#define MAX_NAME_LENGTH 20
#define MAX_SCORE_COUNT 10

enum GameState
{
	GAMESTATE_TITLE,
	GAMESTATE_PLAY,
	GAMESTATE_RESULTS
};

extern int gameScore;
extern bool isGameOver;
extern GameState gameState;
extern vector<pair<TCHAR*, int>> scoreData;

void EarnScore(int rewardScore);
void CheckGameOver(bool state);
bool CompareScore(const pair<TCHAR*, int>& a, const pair<TCHAR*, int>& b);