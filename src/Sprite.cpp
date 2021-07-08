#include "Sprite.h"


void Sprite::Update(int count)
{
  if (count % animationFraction == 0) {
    switch (animationDirection)
    {
      case Both:
        srcRect.x += srcRect.w;
        srcRect.y += srcRect.h;
        break;
      case X:
        srcRect.x += srcRect.w;
        break;
      case Y:
        srcRect.y += srcRect.h;
        break;
      default:
        break;
    }
  }

  // float n = (noise.GetNoise(position.x, position.y) + 1) * Game::SCREEN_WIDTH;
  int randXPos = -4 + round(widthConversionSlope * (noise.GetNoise(position.x, position.y) - (-1)));
  std::cout << randXPos << std::endl;

  if (srcRect.x == objTexture.getWidth()) {
    srcRect.x = 0;
  }

  if (srcRect.y == objTexture.getHeight())
  {
    srcRect.y = 0;
  }

    position.y += scrollSpeed;

    position.x += randXPos;

    if (position.x > Game::SCREEN_WIDTH + srcRect.w)
    {
      position.x = -srcRect.w;
    }
    if (position.y > Game::SCREEN_HEIGHT + srcRect.h)
    {
      position.y = -srcRect.h;
    }
  }

// void Sprite::Update(int count)
// {
//     if (count % animationFraction == 0) {
//       switch (animationDirection)
//       {
//         case Both:
//           srcRect.x += srcRect.w;
//           srcRect.y += srcRect.h;
//           break;
//         case X:
//           srcRect.x += srcRect.w;
//           break;
//         case Y:
//           srcRect.y += srcRect.h;
//           break;
//         default:
//           break;
//       }
//     }
//   // velocity.x = -2;
//   velocity.y = 1;

//   position.x += velocity.x;
//   position.y += velocity.y;

//   // srcRect.x = srcX;
//   // srcRect.y = srcY;

//   if (position.x < 0 || position.x + (objTexture.getWidth() / scale) > Game::SCREEN_WIDTH)
//   {
//     position.x -= velocity.x;
//   }

//   if (position.y < (objTexture.getWidth() / scale) || position.y + (objTexture.getHeight() / scale) > Game::SCREEN_HEIGHT)
//   {
//     position.y -= velocity.y;
//   }

// }
