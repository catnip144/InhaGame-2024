#pragma once

#define SPRITE_SIZE_X 16;
#define SPRITE_SIZE_Y 32;
#define SPRITE_COUNT 8;
#define SPRITE_SCALE 2

#define GUIDE_IMAGE_PATH "images/mario_walk.bmp"

extern HBITMAP hImage_Guide;
extern BITMAP bit_Guide;

void CreateBitmap();