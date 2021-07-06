#ifndef _BACKGROUND_LAYER_H
#define _BACKGROUND_LAYER_H
#include "GameObject.h"
#include "Vector2D.h"

class BackgroundLayer : public GameObject
{
public:
  int speed{1};
  Vector2D bgl1Position;
  Vector2D bgl2Position;
  BackgroundLayer(const char *texturesheet, int width, int height, int x, int y, int scale, short int p_speed = 1);
  ~BackgroundLayer();
  void Accelerate();
  void Decelerate();

  void Update(int count);
  void Render();

private:
  int scrollingOffset;
};
#endif