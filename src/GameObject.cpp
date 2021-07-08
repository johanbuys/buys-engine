#include "GameObject.h"

GameObject::~GameObject(){
  objTexture.free();
}

GameObject::GameObject(std::string texturesheet, int spriteX, int spriteY, int spriteW, int spriteH, int x, int y, int p_scale)
{

  objTexture.loadFromFile(texturesheet);
  position.x = x;
  position.y = y;

  // srcX = spriteX;
  // srcY = spriteY;
  scale = p_scale;

  srcRect.x = spriteX;
  srcRect.y = spriteY;
  srcRect.h = spriteH;
  srcRect.w = spriteW;
}

void GameObject::Render() {
  // SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
  objTexture.render(position.x, position.y, scale, &srcRect);
}

