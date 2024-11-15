#include "GameStates.h"
#include "Game.h"
#include <cassert>

GameOverState::GameOverState(int score, GameStateMachine *parent)
    : GameState(score, parent)
    , retryButton_(86, 400, 115, 39, "retry", "./assets/retry.png")
    , menuButton_(231, 400, 115, 39, "menu", "./assets/menu.png")
{
    assert(TextureManager::instance()->load("./assets/gameover.png", 
                                            "gameover"));
    assert(TextureManager::instance()->load("./assets/background.png",
                                            "background"));
    if (score > MenuState::record_)
        assert(TextureManager::instance()->load("./assets/newRecordBadge.png", 
                                            "badge"));
    else
        assert(TextureManager::instance()->load("./assets/scoreBadge.png", 
                                            "badge"));
}

GameOverState::~GameOverState()
{
    TextureManager::instance()->erase("gameover");
    TextureManager::instance()->erase("score");
    TextureManager::instance()->erase("background");
}

void GameOverState::update()
{
    retryButton_.update();
    menuButton_.update();
    if (retryButton_.clicked())
        parent_->newPlayState();  
    else if (menuButton_.clicked())
        parent_->newMenuState();
}

void GameOverState::render()
{
	TextureManager::instance()->draw("background", 0, 0, WINWIDTH, WINHEIGHT, 0);
    TextureManager::instance()->draw("gameover", 75, 60, 96, 23, 0, 3);
    TextureManager::instance()->draw("badge", 78, 215, 275, 139, 0, 1);
    retryButton_.draw();
    menuButton_.draw();
    drawScore_(score_, 275, 255, 2);
    drawScore_(MenuState::record_, 275, 310, 2);
}
