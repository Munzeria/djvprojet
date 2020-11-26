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
    /*  methodes override; voir GameStateBase.h */
    void execute() override;
    /*  Initialise les elements du jeu  */
    void initialize();
    /*  Methodes permettant de recuperer les elements a afficher    */
    sf::RectangleShape* getPlayerRacket();
    sf::RectangleShape* getIARacket();
    sf::CircleShape* getBall();
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
