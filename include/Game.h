#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {
  public:
    Game();
    ~Game();
    static const int SCREEN_WIDTH {1280};
    static const int SCREEN_HEIGHT {720};

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() { return isRunning; }
    static SDL_Renderer *renderer;

  private:
    bool isRunning;
    SDL_Window *window;
    int count = 0;

};
