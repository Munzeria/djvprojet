#include "Game.h"

/*  CONSTRUCTEUR    */
Game::Game():
    window_height(600),
    window_width(800),
    window(sf::VideoMode(window_width, window_height), "Space Pong"),
    gsSoloPlay(this),
    rendrSoloPlay(this)
{
    currentGameState = &gsSoloPlay;
    currentRenderer = &rendrSoloPlay;
}

void Game::run()
{
    //  Initialisation des gamestates
    gsSoloPlay.initialize();
    //  Boucle principale
    while(window.isOpen())
    {
        //TODO: GESTION TEMPS
        Game::events();
        Game::update();
        Game::display();
    }
}
/*  Game::events() doit recuperer les input utilisateurs    */
void Game::events()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        //  Fermeture de la fenêtre
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

/*  Game::update() gere la normalisation du temps, puis demande au current gamestate d'effectuer ses operations */
void Game::update()
{
    currentGameState->execute();
}

/*  Game::display() affiche la liste des objets utiles au jeu   */
void Game::display()
{
    //  Premierement, vider l'affichage via un clear()
    window.clear();
    currentRenderer->render(&window);
    window.display();
}

/*  Methodes renvoyant la largeur et la hauteur de fenetre  */
int Game::getWindowHeight(){    return window_height;   }
int Game::getWindowWidth(){     return window_width;    }

/*  Methodes renvoyant les differents etats du jeu  */
GameStateBase* Game::getCurrentGameState(){ return currentGameState;    }

GameStateSoloPlay* Game::getGameStateSoloPlay(){    return &gsSoloPlay; }
