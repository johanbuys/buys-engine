#pragma once
#include <stdio.h>
#include <math.h>

void debug(const char *message);

float Lerp(float a, float b, float t);

float InvLerp(float a, float b, float v);

float Remap(float iMin, float iMax, float oMin, float oMax, float v);

double round(double d);