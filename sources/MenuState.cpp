#include "GameStates.h"
#include "InputHandler.h"
#include "Game.h"
#include <cassert>

int MenuState::record_ = 0;

MenuState::MenuState(GameStateMachine *parent)
    : GameState(record_, parent)
    , bird_(Player(180, 285, 17, 12, "player"))
{
    assert(TextureManager::instance()->load("./assets/logo.png", "logo"));
    assert(TextureManager::instance()->load("./assets/touch.png", "touch"));
    assert(TextureManager::instance()->load("./assets/record.png", "record"));
    assert(TextureManager::instance()->load("./assets/background.png",
                                            "background"));
}

MenuState::~MenuState()
{
    TextureManager::instance()->erase("logo");
    TextureManager::instance()->erase("touch");
    TextureManager::instance()->erase("record");
    TextureManager::instance()->erase("background");
}

void MenuState::update()
{
    if (InputHandler::instance()->isMouseButtonDown(0))
        parent_->newPlayState();
}

void MenuState::render()
{
	TextureManager::instance()->draw("background", 0, 0, WINWIDTH, WINHEIGHT, 0);
    TextureManager::instance()->draw("logo", 69, 60, 98, 23, 0, 3);
    TextureManager::instance()->draw("record", 130, 160, 115, 39);
    TextureManager::instance()->draw("touch", 138, 365, 52, 35, 0, 3);
	drawScore_(score_, 280, 163, 3);
    bird_.draw();
}
