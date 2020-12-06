#include "GameStateBase.h"
#include "Game.h"

/*  CONSTRUCTEUR    */
GameStateBase::GameStateBase(Game* g):
    game(g)
{

}

GameStateBase::~GameStateBase()
{

}

Game* GameStateBase::getGame(){ return game; }
