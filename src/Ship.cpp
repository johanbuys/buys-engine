#include "Ship.h"

void Ship::Update(int count)
{
  position.x += static_cast<int>(velocity.x * speed);
  position.y += static_cast<int>(velocity.y * speed);

  srcRect.x = srcX;
  srcRect.y = srcY;

  if (position.y <= 100) {
    position.y = 100;
  }

  if (position.y >= 700)
  {
    position.y = 700;
  }

    if (count % 10 == 0)
    {
      if (srcY == 24)
      {
        srcY = 0;
        // srcY = 0;
      } else if (srcY == 0)
    {
      srcY = 24;
      // srcY = 0;
    }
  }

//
  if (velocity.x == 1) {
    srcX = 48;
  } else if (velocity.x == 0) {
    srcX = 32;
  } else if (velocity.x == -1) {
    srcX = 16;
  }

}