// flappyBird.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main(void)
{
    int frameStart, frameEnd, FrameDuration;

    if (!Game::instance()->init()) {
        std::cerr << "Couldn't initialize Game\n";
        return 1;
    }
    while (Game::instance()->isRunning())
    {
        frameStart = SDL_GetTicks();

        Game::instance()->update();
        Game::instance()->handleEvents();
        Game::instance()->render();

        frameEnd = SDL_GetTicks();
        FrameDuration = frameEnd - frameStart;
        if (FRAME_MS > FrameDuration) SDL_Delay(FRAME_MS - FrameDuration);
    }
    return 0;
}
