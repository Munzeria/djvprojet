#include "GameStateBase.h"

/*  CONSTRUCTEUR    */
GameStateBase::GameStateBase(Game* g):
    game(g)
{

}

Game* GameStateBase::getGame(){ return game; }
