#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include "point.h"
#include "d_heap_sort.h"

void setAngle(std::vector<Point>& A);
void setFirstPoint(std::vector<Point>& vec);
std::vector<Point> createHull(const std::vector<Point>& vec);