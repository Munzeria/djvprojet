#ifndef _GAMESTATEBASE_
#define _GAMESTATEBASE_

#include "GameObject.h"

//  Forward definition de Game
class Game;

class GameStateBase
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
    GameStateBase(Game* g);
    /*  execute() realise les operations liees a un etat du jeu precis.
    **  il est ici virtuel pur car GameStateBase est une classe abstraite non destinee a etre instanciee    */
    virtual void execute() = 0;
    Game* getGame();
/*  ----    VARIABLES   ----    */
private:
    Game* game;
};
#endif // _GAMESTATEBASE_
