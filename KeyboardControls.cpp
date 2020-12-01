#include "KeyboardControls.h"

//  Constructeur
KeyboardControls::KeyboardControls():
    keyUP(false),
    keyDOWN(false),
    keyESCAPE(false),
    keyENTER(false)
    {

    }

//  Resetter
void KeyboardControls::reset()
{
    setKeyUp(false);
    setKeyDown(false);
    setKeyEscape(false);
    setKeyEnter(false);
}

//  Getters
bool KeyboardControls::getKeyUp(){  return keyUP;   }
bool KeyboardControls::getKeyDown(){    return keyDOWN; }
bool KeyboardControls::getKeyEscape(){  return keyESCAPE;   }
bool KeyboardControls::getKeyEnter(){   return keyENTER;    }

//  Setters
void KeyboardControls::setKeyUp(bool b){    keyUP = b;  }
void KeyboardControls::setKeyDown(bool b){  keyDOWN = b;    }
void KeyboardControls::setKeyEscape(bool b){    keyESCAPE = b;  }
void KeyboardControls::setKeyEnter(bool b){ keyENTER = b;   }
