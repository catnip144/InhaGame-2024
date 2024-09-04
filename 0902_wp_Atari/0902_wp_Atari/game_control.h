#pragma once
#include "framework.h"

#define TIMER_ID 1
#define TIMER_INTERVAL 1

#define BG_IMAGE_PATH "images/Background.bmp"

extern int gameScore;
extern bool isGameOver;

void EarnScore(int rewardScore);