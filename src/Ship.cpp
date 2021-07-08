#include "Ship.h"

Ship::Ship(int x, int y, int scale) : GameObject("res/ship.png", 32, 24, 16, 24, x, y, scale) {
  velocity.Zero();
}

void Ship::Update(int count)
{
  position.x += velocity.x;
  position.y += velocity.y;

  // srcRect.x = srcX;
  // srcRect.y = srcY;

  if (position.x < 0 || position.x + (objTexture.getWidth() / scale) >  Game::SCREEN_WIDTH ) {
    position.x -= velocity.x;
  }

  if (position.y < (objTexture.getWidth() / scale) || position.y + (objTexture.getHeight() / scale) > Game::SCREEN_HEIGHT )
  {
    position.y -= velocity.y;
  }

    if (count % 10 == 0)
    {
      if (srcRect.y == 24)
      {
        srcRect.y = 0;
        // srcY = 0;
      }
      else if (srcRect.y == 0)
      {
        srcRect.y = 24;
        // srcY = 0;
      }
  }

  if (velocity.x > 0) {
    srcRect.x = 48;
  } else if (velocity.x == 0) {
    srcRect.x = 32;
  } else if (velocity.x < -1) {
    srcRect.x = 16;
  }

}