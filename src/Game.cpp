#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Ship.h"
#include "BackgroundLayer.h"

// GameObject *planet;
// GameObject *planet2;
Ship *player;
BackgroundLayer *backgroundLayer1;
SDL_Renderer *Game::renderer = nullptr;
// SDL_Texture* bg1;

Game::Game()
{
}

Game::~Game() {

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
  int flags = 0;
  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    SDL_DisplayMode DM;
    if (SDL_GetDesktopDisplayMode(0, &DM) != 0)
    {
      SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
    }
    window = SDL_CreateWindow(title, xpos, ypos, DM.w, DM.h, flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer) {
      SDL_SetRenderDrawColor(renderer ,0, 0, 0, 255);
    }

    SDL_RenderSetLogicalSize(renderer, width, height);
    isRunning = true;

    player = new Ship(width / 2, height - 100, 2);
    backgroundLayer1 = new BackgroundLayer("res/BGLarge.png", 2560, 1440, 0, 0, 1);
    // bg1 = TextureManager::LoadTexture("res/bg2.png");
  } else {
    isRunning = false;
    std::cout << "ERROR in SDL init" << std::endl;
  }
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
    case SDL_QUIT:
      isRunning = false;
      break;
    case SDL_KEYDOWN: {
      switch (event.key.keysym.sym)
      {
        case SDLK_ESCAPE:
          isRunning = false;
          break;
        case SDLK_w:
        case SDLK_UP:
            player->velocity.y = -1;
            backgroundLayer1->Accelerate();
            break;
        case SDLK_DOWN:
        case SDLK_s:
          player->velocity.y = 1;
          break;
        case SDLK_a:
        case SDLK_LEFT:
          player->velocity.x = -1;
          break;
        case SDLK_d:
        case SDLK_RIGHT:
          player->velocity.x = 1;
          break;
      }
      break;
    }
    case SDL_KEYUP:
    {
      switch (event.key.keysym.sym)
      {
        case SDLK_w:
        case SDLK_UP:
          player->velocity.y = 0;
          backgroundLayer1->Decelerate();
          break;
        case SDLK_DOWN:
        case SDLK_s:
          player->velocity.y = 0;
          break;
        case SDLK_a:
        case SDLK_LEFT:
          player->velocity.x = 0;
          break;
        case SDLK_d:
        case SDLK_RIGHT:
          player->velocity.x = 0;
          break;
      }
      break;
    }

    default:
      break;
  }
}

void Game::update() {
  count++;
  player->Update(count);
  backgroundLayer1->Update(count);

          std::cout
      << count << std::endl;
}


void Game::render() {
  SDL_RenderClear(renderer);
  //SDL_RenderCopy(renderer, bg1, NULL, NULL);
  backgroundLayer1->Render();
      // render here
  player->Render();

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Cleaned..." << std::endl;
}