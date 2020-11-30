#ifndef _GAMESTATESOLOPLAY_
#define _GAMESTATESOLOPLAY_

#include "GameStateBase.h"

class Game;

class GameStateSoloPlay: public GameStateBase
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
    GameStateSoloPlay(Game* gameArg);
    /*  methode override; voir GameStateBase.h */
    void execute(sf::Time delta) override;
    /*  Methodes permettant de recuperer les elements a afficher    */
    sf::RectangleShape* getPlayerRacket();
    sf::RectangleShape* getIARacket();
    sf::CircleShape* getBall();
private:
    /*  Methode gerant le mouvement du joueur   */
    void    playerMovement(sf::Time delta);
/*  ----    VARIABLES   ----    */
private:
    /*  Elements du jeu:
    **  -> balle, raquette joueur, raquette IA  */
    sf::RectangleShape  playerRacket,
                        iaRacket;
    sf::CircleShape     ball;
    Game   *game;
};
#endif // _GAMESTATESOLOPLAY_
