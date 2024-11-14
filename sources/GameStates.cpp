#include "GameStates.h"
#include "Game.h"
#include <cassert>

GameState::GameState(int score, GameStateMachine *parent)
		: score_(score)
		, parent_(parent)
{
    assert(parent_);
    assert(TextureManager::instance()->load("./assets/numbers.png",
                                            "numbers"));
};

GameState::~GameState()
{
    TextureManager::instance()->erase("numbers");
}

void GameState::drawScore_(int zoom, int x, int y)
{
    int myscore = score_;
    int i = 1;
    while (myscore /= 10)
        i++;
    myscore = score_;

    for (int j = i; j > 0; j--)
    {
        int digit = myscore / pow(10, j - 1);
        TextureManager::instance()->draw("numbers", x - zoom * 10 * j, y, 
                                         FONTWIDTH, FONTHEIGHT, digit, zoom);
        myscore -= digit * pow(10, j - 1);
    }
}
