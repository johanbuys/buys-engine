#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class Ship : public GameObject
{
public:
  Vector2D velocity;
  int speed {6};
  Ship(int x, int y, int scale);
  ~Ship();

  void Update(int count);
};