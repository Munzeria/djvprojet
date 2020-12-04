#include "GameSettings.h"

GameSettings::GameSettings():
    racketWidth(20),
    racketHeight(100),
    racketSpeed(200),
    ballRadius(10),
    ballSpeed(350)
    {

    }

//  Constructeur de copie
GameSettings::GameSettings(const GameSettings &gs)
{
    racketWidth = gs.racketWidth;
    racketHeight = gs.racketHeight;
    racketSpeed = gs.racketSpeed;
    ballRadius = gs.ballRadius;
    ballSpeed = gs.ballSpeed;
}

//  Operateur d'affectation
GameSettings& GameSettings::operator=(const GameSettings &gs)
{
    racketWidth = gs.racketWidth;
    racketHeight = gs.racketHeight;
    racketSpeed = gs.racketSpeed;
    ballRadius = gs.ballRadius;
    ballSpeed = gs.ballSpeed;
}

int GameSettings::getRacketWidth(){  return racketWidth; }
int GameSettings::getRacketHeight(){ return racketHeight;}
int GameSettings::getRacketSpeed(){  return racketSpeed; }
int GameSettings::getBallRadius(){   return ballRadius;  }
int GameSettings::getBallSpeed(){    return ballSpeed;   }
