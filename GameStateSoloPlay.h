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
    /*  Constructeur copie, indisponible    */
    GameStateSoloPlay(const GameStateSoloPlay &gssp) = delete;
    /*  Destructeur */
    virtual ~GameStateSoloPlay();
    /*  Operateur d'affectation, indisponible   */
    GameStateSoloPlay& operator=(const GameStateSoloPlay &gssp) = delete;
    /*  methode override; voir GameStateBase.h */
    void execute(sf::Time delta) override;
    /*  Methodes permettant de recuperer les elements a afficher    */
    sf::RectangleShape* getPlayerRacket();
    sf::RectangleShape* getIARacket();
    sf::CircleShape*    getBall();
    sf::Text*           getScoreText();
    bool                getGamePaused();
    bool                getGameEnded();
    //  getScoreDiff renvoie la difference de score entre joueur et ia. Positif, joueur gagne, negatif, ia gagne
    int                 getScoreDiff();
private:
    /*  Methode gerant le mouvement du joueur   */
    void    playerMovement(sf::Time delta);
    void    iaMovement(sf::Time delta);
    /*  Methode gerant le deplacement de la balle   */
    void    ballMovement(sf::Time delta);
    /*  Methode pour verifier si une rackette peut se déplacer dans la direction voulue */
    bool    racketMovementAllowed(sf::RectangleShape racket, float movement);
    /*  Methode verifiant la collision entre la balle et l'une des raquettes    */
    bool    ballCollision(sf::RectangleShape racket);
    /*  Reinitialise la balle au centre et les raquettes */
    void    resetBall();
/*  ----    VARIABLES   ----    */
private:
    /*  Elements du jeu:
    **  -> balle, raquette joueur, raquette IA  */
    sf::RectangleShape  playerRacket,
                        iaRacket;
    sf::CircleShape     ball;
    sf::Vector2f        ballDirection;
    int                 playerScore,
                        iaScore;
    sf::Text            scoreText;
    bool                gamePaused,
                        gameEnded;
    sf::Time            lastCheck;
};
#endif // _GAMESTATESOLOPLAY_
