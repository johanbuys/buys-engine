#pragma once
#include "Game.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include <string>

class GameObject {
  public:
    Vector2D position;
    Vector2D velocity;
    int speed = 3;
    GameObject(std::string texturesheet, int spriteX, int spriteY, int spriteW, int spriteH, int x, int y, int scale);
    ~GameObject();

    void Update(int count);
    void Render();

  protected: 

    int dt;
    int srcX;
    int srcY;
    int scale;
    // bool animate;

    SDL_Renderer *renderer;
    TextureManager objTexture;
    SDL_Rect srcRect;
    SDL_Rect destRect;
};