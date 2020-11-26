/*  Developpement de jeux vidéos - Projet
**  Space Pong
**  ----------
**  Classe Game destinee a etre le contenant des autres elements du jeu */
#ifndef _GAME_
#define _GAME_

#include <SFML/Graphics.hpp>

#include "GameStateBase.h"
#include "GameStateSoloPlay.h"
#include "Renderer.h"
#include "RendererSoloPlay.h"

class Game
{
/*  ----    METHODES    ----    */
private:
    /*      events() gerera les evenements tels que input clavier/souris, fermeture du jeu  */
    void    events();
    /*      update() servira a appeller la fonction update() du GameState actuel
    **      update aura aussi pour tache de gerer la normalisation du temps par frame   */
    void    update();
    /*      display() sert à l'affichage des éléments du jeu    */
    void    display();
public:
    /*      Constructeur    */
            Game();
    /*      run() sert a lancer la boucle principale du jeu */
    void    run();
    /*      Methodes renvoyant les differents etats du jeu  */
    GameStateBase*  getCurrentGameState();
    GameStateSoloPlay*  getGameStateSoloPlay();

    /*  Methodes relatives a la taille de la fenetre    */
    int     getWindowHeight();
    int     getWindowWidth();

/*  ----    VARIABLES   ----    */
private:
    int window_height;
    int window_width;
    sf::RenderWindow    window;
    //  GAMESTATES
    GameStateBase*      currentGameState;

    GameStateSoloPlay   gsSoloPlay;
    //  RENDERERS
    Renderer*           currentRenderer;

    RendererSoloPlay   rendrSoloPlay;
};
#endif // _GAME_
