#include "Game.h"
#include "GameStateSoloPlay.h"
#include <iostream>

/*  Constructeur    */
GameStateSoloPlay::GameStateSoloPlay(Game *gameArg):
    GameStateBase(gameArg),
    playerRacket(),
    iaRacket(),
    ball()
{
    playerRacket.setPosition(5,
                             getGame()->getWindowHeight()/2 - (getGame()->getSettings()->getRacketHeight())/2);
    iaRacket.setPosition(getGame()->getWindowWidth() - getGame()->getSettings()->getRacketWidth() - 5,
                         getGame()->getWindowHeight()/2 - (getGame()->getSettings()->getRacketHeight())/2);
    ball.setPosition(getGame()->getWindowWidth()/2, getGame()->getWindowHeight()/2);
}

/*  execute(): operations liees a cet etat du jeu   */
void GameStateSoloPlay::execute(sf::Time delta)
{
    playerMovement(delta);
}

/*  playerMovement() gere le mouvement du joueur. Normalise par le delta de execute()   */
void GameStateSoloPlay::playerMovement(sf::Time delta)
{
    float movement{0};
    //  Definir la direction du mouvement. Si chaque key est pressee en meme temps, mouvement nul
    if (getGame()->getKeyboard()->getKeyUp())
        movement++;
    if (getGame()->getKeyboard()->getKeyDown())
        movement--;
    /*  Si mouvement positif (vers le haut) mais y = 0, pas de mouvement possible
    **  Pareil pour mouvement negatif et y = hauteur fenetre - hauteur raquette
    **  Comme ca, impossible de sortir de la fenetre
    */
    if (playerRacket.getPosition().y <= 0 && movement > 0)
        return;
    if (playerRacket.getPosition().y >= getGame()->getWindowHeight()-getGame()->getSettings()->getRacketHeight() && movement < 0)
        return;

    playerRacket.move(0, -getGame()->getSettings()->getRacketSpeed() * movement * delta.asSeconds());
}

/*  Getters */
sf::RectangleShape* GameStateSoloPlay::getPlayerRacket(){    return &playerRacket;    }
sf::RectangleShape* GameStateSoloPlay::getIARacket(){    return &iaRacket;    }
sf::CircleShape* GameStateSoloPlay::getBall(){   return &ball;    }
