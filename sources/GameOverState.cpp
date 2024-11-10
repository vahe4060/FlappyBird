#include "GameStates.h"
#include "Game.h"
#include <cassert>

GameOverState::GameOverState()
    : GameState()
    , retryButton_(190, 280, 46, 46, "retry", "./assets/retry.png")
{
    assert(TextureManager::instance()->load("./assets/gameover.png", "gameover"));
    assert(TextureManager::instance()->load("./assets/numbers.png", "numbers"));
    assert(TextureManager::instance()->load("./assets/score.png", "score"));
}

GameOverState::~GameOverState()
{
    TextureManager::instance()->erase("gameover");
    TextureManager::instance()->erase("numbers");
    TextureManager::instance()->erase("score");
}

void GameOverState::update()
{
    retryButton_.update();
    if (retryButton_.clicked())
    {
        Game::instance()->resetScore();
        Game::instance()->getStateMachine()->popState();
        Game::instance()->getStateMachine()->pushState(new PlayState());
    }
}

void GameOverState::render()
{
    TextureManager::instance()->draw("gameover", 75, 50, 96, 23, 0, 3);
    TextureManager::instance()->draw("score", 80, 202, 40, 13, 0, 3);
    Game::instance()->printScore(4,350,200);
    retryButton_.draw();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    