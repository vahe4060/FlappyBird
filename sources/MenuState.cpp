#include "GameStates.h"
#include "InputHandler.h"
#include "Game.h"
#include <cassert>

MenuState::MenuState(int record, Game *parent)
    : GameState(record, parent)
    , bird_(Player(180, 250, 17, 12, "player"))
{
    assert(TextureManager::instance()->load("./assets/logo.png", "logo"));
    assert(TextureManager::instance()->load("./assets/touch.png", "touch"));
    assert(TextureManager::instance()->load("./assets/background.png",
                                            "background"));
}

MenuState::~MenuState()
{
    TextureManager::instance()->erase("logo");
    TextureManager::instance()->erase("touch");
    TextureManager::instance()->erase("background");
}

void MenuState::update()
{
    if (InputHandler::instance()->isMouseButtonDown(0))
        parent_->newGame();
}

void MenuState::render()
{
	TextureManager::instance()->draw("background", 0, 0, WINWIDTH, WINHEIGHT, 0);
    TextureManager::instance()->draw("logo", 69, 100, 98, 23, 0, 3);
    TextureManager::instance()->draw("touch", 138, 300, 52, 35, 0, 3);
    bird_.draw();
	drawScore_(5, 240, 50);
}
