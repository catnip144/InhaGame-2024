#pragma once
#include "framework.h"

int gameScore = 0;
bool isGameOver = false;

void EarnScore(int rewardScore)
{
	gameScore += rewardScore;
}

void SetGameOver(bool state)
{
	isGameOver = state;
}