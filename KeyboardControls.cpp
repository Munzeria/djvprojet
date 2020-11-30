#include "KeyboardControls.h"

//  Constructeur
KeyboardControls::KeyboardControls():
    keyUP(false),
    keyDOWN(false)
    {

    }

//  Resetter
void KeyboardControls::reset()
{
    setKeyUp(false);
    setKeyDown(false);
}

//  Getters
bool KeyboardControls::getKeyUp(){  return keyUP;   }
bool KeyboardControls::getKeyDown(){    return keyDOWN; }

//  Setters
void KeyboardControls::setKeyUp(bool b){    keyUP = b;  }
void KeyboardControls::setKeyDown(bool b){  keyDOWN = b;    }
