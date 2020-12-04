#include "GameStateBase.h"
#include "Game.h"

/*  CONSTRUCTEUR    */
GameStateBase::GameStateBase(Game* g):
    game(g)
{

}

GameStateBase::~GameStateBase()
{
    delete game;
}

Game* GameStateBase::getGame(){ return game; }
