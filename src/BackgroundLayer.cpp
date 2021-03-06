#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer(const char *texturesheet, int width, int height, int x, int y, int scale, short int p_speed) : GameObject(texturesheet, 0, 0, width, height, x, y, scale)
{
  speed = p_speed;
  bgl1Position.Zero();
  bgl2Position.x = 0;
  bgl2Position.y = -objTexture.getHeight();
}

void BackgroundLayer::Accelerate()
{
  speed = speed * 2;
}

void BackgroundLayer::Decelerate()
{
  speed = speed / 2;
}

void BackgroundLayer::Update(int count)
{
  bgl1Position.y += speed;
  bgl2Position.y += speed;


  if (bgl1Position.y >= objTexture.getHeight())
  {
    // position.y = (srcRect.h / 2) * -1;
    bgl1Position.y = -objTexture.getHeight();
  }
  if (bgl2Position.y >= objTexture.getHeight())
  {
    // position.y = (srcRect.h / 2) * -1;
    bgl2Position.y = -objTexture.getHeight();
  }
}

void BackgroundLayer::Render()
{
  objTexture.render(position.x, bgl1Position.y, scale, &srcRect);
  objTexture.render(position.x, bgl2Position.y, scale, &srcRect);
}