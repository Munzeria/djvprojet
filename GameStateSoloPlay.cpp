#include "Game.h"
#include "GameStateSoloPlay.h"

/*  Constructeur    */
GameStateSoloPlay::GameStateSoloPlay(Game *gameArg):
    GameStateBase(gameArg),
    playerRacket(),
    iaRacket(),
    ball()
{
    playerRacket.setPosition(5, getGame()->getWindowHeight()/2);
    iaRacket.setPosition(getGame()->getWindowWidth()-30, getGame()->getWindowHeight()/2);
    ball.setPosition(getGame()->getWindowWidth()/2, getGame()->getWindowHeight()/2);
}

/*  execute(): operations liees a cet etat du jeu   */
void GameStateSoloPlay::execute()
{

}

void GameStateSoloPlay::initialize()
{

}

/*  Getters */
sf::RectangleShape* GameStateSoloPlay::getPlayerRacket(){    return &playerRacket;    }
sf::RectangleShape* GameStateSoloPlay::getIARacket(){    return &iaRacket;    }
sf::CircleShape* GameStateSoloPlay::getBall(){   return &ball;    }
