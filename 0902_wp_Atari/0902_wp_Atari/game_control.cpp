#pragma once
#include "framework.h"
#include "game_control.h"

HBITMAP	hBgImage;
BITMAP	bitBg;

HBITMAP	hMultiplierItemImage;
BITMAP	bitMultiplierItem;

HBITMAP	hStickyItemImage;
BITMAP	bitStickyItem;

HBITMAP	hStretchItemImage;
BITMAP	bitStretchItem;

int gameScore = 0;
bool isGameOver = false;
GameState gameState = GAMESTATE_TITLE;
vector<pair<TCHAR*, int>> scoreData(MAX_SCORE_COUNT);

void EarnScore(int rewardScore)
{
	gameScore += rewardScore;
}

void CheckGameOver(bool state)
{
	isGameOver = state;
}

bool CompareScore(const pair<TCHAR*, int>& a, const pair<TCHAR*, int>& b)
{
	return a.second > b.second;
}