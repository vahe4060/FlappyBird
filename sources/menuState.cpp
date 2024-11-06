#include "gameStates.h"
#include "inputHandler.h"
#include "game.h"

menuState::menuState()
{
}

bool menuState::onEnter()
{
    if (!textureManager::instance()->load("assets/logo.png", "logo")) return false;
    if (!textureManager::instance()->load("assets/button.png", "touch")) return false;
    
    bird = new player(new loaderParams(180, 250, 17, 12, "player"));
    if (bird == nullptr) return false;

    return true;
}


bool menuState::onExit()
{
    bird->~player();
    delete bird;

    textureManager::instance()->erase("logo");
    textureManager::instance()->erase("touch");
    return true;
}


void menuState::update()
{
    //bird->draw();
    if (inputHandler::instance()->isMouseButtonDown(0))
    {
        game::instance()->getStateMachine()->popState();
        game::instance()->getStateMachine()->pushState(new PlayState());
    }
}


void menuState::render()
{
    textureManager::instance()->draw("logo", 69, 100, 98, 23, 0, 3);
    textureManager::instance()->draw("touch", 138, 300, 52, 35, 0, 3);
    bird->draw();
    SDL_Delay(50);
}