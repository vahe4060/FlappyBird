#include "GameStates.h"
#include "Game.h"

GameOverState::GameOverState()
{
}

bool GameOverState::onEnter()
{
    if (!TextureManager::instance()->load("assets/gameover.png", "gameover")) return false;
    if (!TextureManager::instance()->load("assets/numbers.png", "numbers")) return false;
    if (!TextureManager::instance()->load("assets/score.png", "score")) return false;


    retry = new ClickButton(new LoaderParams(190,280,46,46,"retry"), "assets/retry.png");


    return true;
}


bool GameOverState::onExit()
{
    TextureManager::instance()->erase("gameover");
    TextureManager::instance()->erase("numbers");
    TextureManager::instance()->erase("score");
    // retry->~ClickButton();
    delete retry;
    return true;
}


void GameOverState::update()
{
    retry->update();
    if (retry->clicked)
    {
        Game::instance()->reset();
        Game::instance()->getStateMachine()->popState();
        Game::instance()->getStateMachine()->pushState(new PlayState());
    }
}


void GameOverState::render()
{
    TextureManager::instance()->draw("gameover", 75, 50, 96, 23, 0, 3);
    TextureManager::instance()->draw("score", 80, 202, 40, 13, 0, 3);

    Game::instance()->printScore(4,350,200);
    retry->draw();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    