#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Ship.h"
#include "BackgroundLayer.h"
#include "Sprite.h"

// GameObject *planet;
// GameObject *planet2;
Ship *player;
Sprite *enemySm;

BackgroundLayer *backgroundLayer1;
BackgroundLayer *backgroundLayer2;
SDL_Renderer *Game::renderer = nullptr;
// Sprite *planet1;
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
    enemySm = new Sprite("res/enemy-small.png", Game::SCREEN_WIDTH / 2, -10, 0, 0, 16, 16, 2, 30, X);
    // planet1 = new Sprite("res/planet-grey.png", (rand() % Game::SCREEN_WIDTH - 100), (rand() % Game::SCREEN_HEIGHT), 0, 0, 100, 100, 2, 30, X);
    backgroundLayer1 = new BackgroundLayer("res/BGLarge.png", 2560, 1440, 0, 0, 1);
    // backgroundLayer2 = new BackgroundLayer("res/PlanetsLayer1.png", 1280, 720, 0, 0, 1, 2);
    // bg1 = TextureManager::LoadTexture("res/bg2.png");
  } else {
    isRunning = false;
    std::cout << "ERROR in SDL init" << std::endl;
  }
}

void Game::handleEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event) != 0)
  {
    if (event.type == SDL_QUIT)
    {
      isRunning = false;
    }
    else if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
    {
      switch (event.key.keysym.sym)
      {
      case SDLK_ESCAPE:
        isRunning = false;
        break;
      case SDLK_w:
      case SDLK_UP:
        player->velocity.y -= player->speed;
        // backgroundLayer1->Accelerate();
        // backgroundLayer2->Accelerate();

        break;
      case SDLK_DOWN:
      case SDLK_s:
        player->velocity.y += player->speed;
        break;
      case SDLK_a:
      case SDLK_LEFT:
        player->velocity.x -= player->speed;
        break;
      case SDLK_d:
      case SDLK_RIGHT:
        player->velocity.x += player->speed;
        break;
      }
      break;
    }
    else if (event.type == SDL_KEYUP && event.key.repeat == 0)
    {
      switch (event.key.keysym.sym)
      {
      case SDLK_w:
      case SDLK_UP:
        player->velocity.y += player->speed;
        // backgroundLayer1->Decelerate();
        // backgroundLayer2->Decelerate();
        
        break;
      case SDLK_DOWN:
      case SDLK_s:
        player->velocity.y -= player->speed;
        break;
      case SDLK_a:
      case SDLK_LEFT:
        player->velocity.x += player->speed;
        break;
      case SDLK_d:
      case SDLK_RIGHT:
        player->velocity.x -= player->speed;
        break;
      }
    }
  }
}

void Game::update() {
  count++;
  player->Update(count);
  backgroundLayer1->Update(count);
  // backgroundLayer2->Update(count);
  // planet1->Update(count);
  enemySm->Update(count);


}


void Game::render() {
  SDL_RenderClear(renderer);
  //SDL_RenderCopy(renderer, bg1, NULL, NULL);
  backgroundLayer1->Render();
  // backgroundLayer2->Render();
  // planet1->Render();
  // render here
  enemySm->Render();
  player->Render();

  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Cleaned..." << std::endl;
}