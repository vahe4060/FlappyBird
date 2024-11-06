#include "gameStates.h"
#include "game.h"

gameOverState::gameOverState()
{
}

bool gameOverState::onEnter()
{
    if (!textureManager::instance()->load("assets/gameover.png", "gameover")) return false;
    if (!textureManager::instance()->load("assets/numbers.png", "numbers")) return false;
    if (!textureManager::instance()->load("assets/score.png", "score")) return false;


    retry = new ClickButton(new loaderParams(190,280,46,46,"retry"), "assets/retry.png");


    return true;
}


bool gameOverState::onExit()
{
    textureManager::instance()->erase("gameover");
    textureManager::instance()->erase("numbers");
    textureManager::instance()->erase("score");
    retry->~ClickButton();
    delete retry;
    return true;
}


void gameOverState::update()
{
    retry->update();
    if (retry->clicked)
    {
        game::instance()->reset();
        game::instance()->getStateMachine()->popState();
        game::instance()->getStateMachine()->pushState(new PlayState());
    }
}


void gameOverState::render()
{
    textureManager::instance()->draw("gameover", 75, 50, 96, 23, 0, 3);
    textureManager::instance()->draw("score", 80, 202, 40, 13, 0, 3);

    game::instance()->printScore(4,350,200);
    retry->draw();
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    