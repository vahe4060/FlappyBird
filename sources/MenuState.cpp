#include "GameStates.h"
#include "InputHandler.h"
#include "Game.h"

bool MenuState::onEnter()
{
    if (!TextureManager::instance()->load("./assets/logo.png", "logo"))
        return false;
    if (!TextureManager::instance()->load("./assets/button.png", "touch"))
        return false;

    bird_ = new Player(180, 250, 17, 12, "player");
    if (bird_ == nullptr)
        return false;
    return true;
}


bool MenuState::onExit()
{
    delete bird_;
    TextureManager::instance()->erase("logo");
    TextureManager::instance()->erase("touch");
    return true;
}


void MenuState::update()
{
    if (InputHandler::instance()->isMouseButtonDown(0))
    {
        Game::instance()->getStateMachine()->popState();
        Game::instance()->getStateMachine()->pushState(new PlayState());
    }
}


void MenuState::render()
{
    TextureManager::instance()->draw("logo", 69, 100, 98, 23, 0, 3);
    TextureManager::instance()->draw("touch", 138, 300, 52, 35, 0, 3);
    bird_->draw();
    SDL_Delay(50);
}