#include "GameSettings.h"

GameSettings::GameSettings():
    racketWidth(20),
    racketHeight(100),
    racketSpeed(200),
    ballRadius(10),
    ballSpeed(350)
    {

    }

int GameSettings::getRacketWidth(){  return racketWidth; }
int GameSettings::getRacketHeight(){ return racketHeight;}
int GameSettings::getRacketSpeed(){  return racketSpeed; }
int GameSettings::getBallRadius(){   return ballRadius;  }
int GameSettings::getBallSpeed(){    return ballSpeed;   }
