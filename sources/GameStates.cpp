#include "GameStates.h"
#include "Game.h"
#include <cassert>

GameState::GameState(int score, GameStateMachine *parent)
		: score_(score)
		, parent_(parent)
{
    assert(parent_);
    InputHandler::instance()->reset();
    assert(TextureManager::instance()->load("./assets/numbers.png",
                                            "numbers"));
};

GameState::~GameState()
{
    TextureManager::instance()->erase("numbers");
}

int GameState::drawScore_(int score, int x, int y, int zoom)
{
    if (score < 0)
        return 0;
    if (score >= 10)
    {
        int len = drawScore_(score / 10, x, y, zoom);
        return len + drawScore_(score % 10, x + len, y, zoom);
    }
    TextureManager::instance()->draw("numbers", x, y, FONTWIDTH, FONTHEIGHT,
                                     score, zoom);
    return FONTWIDTH * zoom;
}
