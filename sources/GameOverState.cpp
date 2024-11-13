#include "GameStates.h"
#include "Game.h"
#include <cassert>

GameOverState::GameOverState(int score, Game *parent)
    : GameState(score, parent)
    , retryButton_(190, 280, 46, 46, "retry", "./assets/retry.png")
{
    assert(TextureManager::instance()->load("./assets/gameover.png", 
                                            "gameover"));
    assert(TextureManager::instance()->load("./assets/score.png", 
                                            "score"));
    assert(TextureManager::instance()->load("./assets/background.png",
                                            "background"));
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
    if (retryButton_.clicked())
        parent_->newGame();
}

void GameOverState::render()
{
	TextureManager::instance()->draw("background", 0, 0, WINWIDTH, WINHEIGHT, 0);
    TextureManager::instance()->draw("gameover", 75, 50, 96, 23, 0, 3);
    TextureManager::instance()->draw("score", 80, 202, 40, 13, 0, 3);
    retryButton_.draw();
    drawScore_(4, 350, 200);
}
