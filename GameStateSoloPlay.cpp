#include "Game.h"
#include "GameStateSoloPlay.h"
#include <iostream>
#include <cmath>
#include <SFML/System/Vector2.hpp>

/*  Constructeur    */
GameStateSoloPlay::GameStateSoloPlay(Game *gameArg):
    GameStateBase(gameArg),
    playerRacket(),
    iaRacket(),
    ball(),
    ballDirection(0, 0),
    playerScore(0),
    iaScore(0),
    scoreText()
{
    //  Definition des origines
    playerRacket.setOrigin(getGame()->getSettings()->getRacketWidth()/2, getGame()->getSettings()->getRacketHeight()/2);
    iaRacket.setOrigin(getGame()->getSettings()->getRacketWidth()/2, getGame()->getSettings()->getRacketHeight()/2);
    ball.setOrigin(getGame()->getSettings()->getBallRadius(), getGame()->getSettings()->getBallRadius());

    resetBall();
}

GameStateSoloPlay::~GameStateSoloPlay()
{
    //  ~GameStateBase() sera appele, pas d'autre pointeur a delete
}

/*  execute(): operations liees a cet etat du jeu   */
void GameStateSoloPlay::execute(sf::Time delta)
{
    //  Si l'utilisateur appuie sur escape, quitte la partie
    if (getGame()->getKeyboard()->getKeyEscape())
    {
        getGame()->switchGameState(Game::MAINMENU);
        return;
    }
    //  Verification d'un "goal"
    if (ball.getPosition().x < 0)  //IA marque
    {
        iaScore++;
        resetBall();
    }
    if (ball.getPosition().x > getGame()->getWindowWidth()) //le joueur marque
    {
        playerScore++;
        resetBall();
    }
    playerMovement(delta);
    iaMovement(delta);
    ballMovement(delta);
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
    //  Verification de la possibilite de mouvement
    if (racketMovementAllowed(playerRacket, movement))
        playerRacket.move(0, -getGame()->getSettings()->getRacketSpeed() * movement * delta.asSeconds());
}

void GameStateSoloPlay::iaMovement(sf::Time delta)
{
    float movement{0};
    //  Definir direction du mouvement, selon la position de la balle
    if (iaRacket.getPosition().y > ball.getPosition().y)
        movement++;
    if (iaRacket.getPosition().y < ball.getPosition().y)
        movement--;
    //  Verification possibilite de mouvement
    if (racketMovementAllowed(iaRacket, movement))
        iaRacket.move(0, -getGame()->getSettings()->getRacketSpeed() * movement * delta.asSeconds());
}

void GameStateSoloPlay::ballMovement(sf::Time delta)
{
    /*  Verifier si une direction a ete choisie. Si ce n'est pas le cas (debut de partie),
    **  definir une direction pour la balle
    */
    if (ballDirection.x == 0 && ballDirection.y == 0)
    {
        srand(time(NULL));  //random seed
        ballDirection.x = rand() / (RAND_MAX + 2.) - 1.;
        ballDirection.y = rand() / (RAND_MAX + 2.) - 1.;
        //  Normalisation du vecteur de deplacement
        float magnitude{sqrt(pow(ballDirection.x, 2) + pow(ballDirection.y, 2))};
        ballDirection.x = ballDirection.x / magnitude;
        ballDirection.y = ballDirection.y / magnitude;
        /*  Operation impossible a faire directement, pour une raison inconnue le compilateur n'accepte pas
        **  l'operateur / entre un vecteur et un float, bien que l'operateur soit surcharge dans Vector2.hpp    */
    }

    /*  Collisions avec bord de la fenetre  */
    //  Haut de la fenetre
    if (ball.getPosition().y <= getGame()->getSettings()->getBallRadius())
        ballDirection.y = ballDirection.y * -1.;
    //  Bas de la fenetre
    if (ball.getPosition().y >= getGame()->getWindowHeight() - ball.getRadius())
        ballDirection.y = ballDirection.y * -1.;
    /*  Collisions avec raquettes   */
    if (ballCollision(playerRacket))
    {
        ballDirection.x = ballDirection.x * -1;
    }
    if (ballCollision(iaRacket))
        ballDirection.x = ballDirection.x * -1;

    ball.move(ballDirection.x * getGame()->getSettings()->getBallSpeed() * delta.asSeconds(),
              ballDirection.y * getGame()->getSettings()->getBallSpeed() * delta.asSeconds());
}

bool GameStateSoloPlay::racketMovementAllowed(sf::RectangleShape racket, float movement)
{
    /*  Si mouvement positif (vers le haut) mais y = 0 + moitie hauteur raquette, pas de mouvement possible
    **  Pareil pour mouvement negatif et y = hauteur fenetre - moitie hauteur raquette
    **  Comme ca, impossible de sortir de la fenetre
    */
    if (racket.getPosition().y <= getGame()->getSettings()->getRacketHeight()/2 && movement > 0)
        return false;
    if (racket.getPosition().y >= getGame()->getWindowHeight()-getGame()->getSettings()->getRacketHeight()/2 && movement < 0)
        return false;
    return true;
}

bool GameStateSoloPlay::ballCollision(sf::RectangleShape racket)
{
    //  Etape 1, calculer la distance sur chaque axe entre le rectangle et la balle
    float distanceX = abs(ball.getPosition().x - racket.getPosition().x);
    float distanceY = abs(ball.getPosition().y - racket.getPosition().y);
    //  Si ces distances sont plus grandes que le rayon du cercle + la moitie du rectangle sur un axe, pas de collision
    if (distanceX > (getGame()->getSettings()->getRacketWidth()/2 + getGame()->getSettings()->getBallRadius()))
        return false;
    if (distanceY > (getGame()->getSettings()->getRacketHeight()/2 + getGame()->getSettings()->getBallRadius()))
        return false;
    //  Verifier si la balle se trouve dans un rectangle etendu par le rayon du cercle
    if (distanceX <= (getGame()->getSettings()->getRacketWidth()/2 + getGame()->getSettings()->getBallRadius()))
        return true;
    if (distanceY <= (getGame()->getSettings()->getRacketHeight()/2 + getGame()->getSettings()->getBallRadius()))
        return true;
    //  Dernier test a effectuer; TODO
    return true;
}

void GameStateSoloPlay::resetBall()
{
    //  Direction nulle pour la balle
    ballDirection.x = 0.;
    ballDirection.y = 0.;
    //  Placement des objets (base sur leur origine)
    playerRacket.setPosition(5 + getGame()->getSettings()->getRacketWidth()/2,
                             getGame()->getWindowHeight()/2);
    iaRacket.setPosition(getGame()->getWindowWidth() - getGame()->getSettings()->getRacketWidth()/2 - 5,
                         getGame()->getWindowHeight()/2);

    ball.setPosition(getGame()->getWindowWidth()/2, getGame()->getWindowHeight()/2);

    //  Texte de score
    scoreText.setString(std::to_string(playerScore) + " < > " + std::to_string(iaScore));
}

/*  Getters */
sf::RectangleShape* GameStateSoloPlay::getPlayerRacket(){    return &playerRacket;    }
sf::RectangleShape* GameStateSoloPlay::getIARacket(){    return &iaRacket;    }
sf::CircleShape* GameStateSoloPlay::getBall(){   return &ball;    }
sf::Text* GameStateSoloPlay::getScoreText(){    return &scoreText;  }
