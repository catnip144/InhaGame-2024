#pragma once

#define COST_STRAIGHT 10
#define COST_DIAGONAL 14

extern bool FindPath();

int Heuristic(POINT pos1, POINT pos2);
