// flappyBird.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main(int argc,  char **argv)
{
    const int FPS = 24;
    int frameStart, frameEnd, FrameDuration;

    if (!Game::instance()->init()) {
        std::cerr << "couldn't initialize Game..\n";
        return 1;
    }

    while (Game::instance()->isRunning)
    {
        frameStart = SDL_GetTicks();

        Game::instance()->update();
        Game::instance()->handleEvents();
        Game::instance()->render();

        frameEnd = SDL_GetTicks();
        FrameDuration = frameEnd - frameStart;
        if (1000 / FPS > FrameDuration) SDL_Delay(1000 / FPS - FrameDuration);
    }
    Game::instance()->clean();

    return 0;
}
