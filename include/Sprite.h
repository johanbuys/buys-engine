#pragma once
#include "GameObject.h"
#include <string>
#include "Vector2D.h"
#include "FastNoiseLite.h"
#include "utils.h"

enum AnimationDirection
{
  X,
  Y,
  Both
};

class Sprite : public GameObject
{
public:
  int animationFraction;
  int scrollSpeed{2};
  Vector2D velocity;
  AnimationDirection animationDirection;
  Sprite(std::string textureSheet, int x, int y, int posX, int posY, int width, int height, int scale, int p_animationFraction, AnimationDirection p_animationDirection) : GameObject(textureSheet, posX, posY, width, height, x, y, scale)
  {
    animationFraction = p_animationFraction;
    animationDirection = p_animationDirection;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);
    widthConversionSlope = 1.0 * (4 - (-4)) / (1 - (-1));
  };
  ~Sprite();

  void Update(int count);
private:
  FastNoiseLite noise;
  double widthConversionSlope;
};