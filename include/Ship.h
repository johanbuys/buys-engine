#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class Ship : public GameObject
{
public:
  int speed {6};
  Ship(int x, int y, int scale) : GameObject("res/ship.png", 32, 24, 16, 24, x, y, scale) {};
  ~Ship();

  void Update(int count);
};