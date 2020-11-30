#include "GameSettings.h"

GameSettings::GameSettings():
    racketWidth(30),
    racketHeight(120),
    racketSpeed(120)
    {

    }

int GameSettings::getRacketWidth(){  return racketWidth; }
int GameSettings::getRacketHeight(){ return racketHeight;}
int GameSettings::getRacketSpeed(){  return racketSpeed; }
