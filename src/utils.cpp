#include "utils.h"

void debug(const char* message) {
  printf(message);
}

float Lerp(float a, float b, float t)
{
  return (1.0f - t) * a + b * t;
}

float InvLerp(float a, float b, float v)
{
  return (v - a) / (b - a);
}

float Remap(float iMin, float iMax, float oMin, float oMax, float v)
{
  float t = InvLerp(iMin, iMax, v);
  return Lerp(oMin, oMax, t);
}

double round(double d)
{
  return floor(d + 0.5);
}