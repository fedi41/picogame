#pragma once
#include <math.h>


typedef struct { double x; double y; } vec2;


float distance_v2(vec2 p1, vec2 p2);
vec2 move_towards_v2(vec2 current, vec2 target, float max_distance_delta);
