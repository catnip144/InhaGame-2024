#pragma once

#define COST_STRAIGHT 10
#define COST_DIAGONAL 14

extern vector<POINT> path;
extern vector<POINT> FindPath();

int ManhattanDistance(POINT pos1, POINT pos2);
