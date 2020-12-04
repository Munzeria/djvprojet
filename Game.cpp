#include "Game.h"
#include <iostream>

/*  CONSTRUCTEUR    */
Game::Game():
    window_height(600),
    window_width(800),
    window(sf::VideoMode(window_width, window_height), "Space Pong"),
    settings(),
    keyboard(),
    gsSoloPlay(this),
    gsMainMenu(this),
    rendrSoloPlay(this),
    rendrMainMenu(this)
{
    switchGameState(MAINMENU);
}

/*  DESTRUCTEUR */
Game::~Game()
{
    delete currentGameState;
    delete currentRenderer;
}

void Game::run()
{
    //  utiliser sf::clock pour gerer le temps
    sf::Clock clock;
    //  Boucle principale
    while(window.isOpen())
    {
        //  elapsed() est un sf::time representant le temps passe depuis la derniere iteration, recupere gracec a clock.restart()
        sf::Time elapsed = clock.restart();

        Game::events();
        Game::update(elapsed);
        Game::display();
    }
}

void Game::switchGameState(int targetGS)
{
    switch(targetGS)
    {
    case Game::MAINMENU:
        //  Main menu cleanup fonction ?
        currentGameState = getGameStateMainMenu();
        currentRenderer = &rendrMainMenu;
        break;
    case Game::SOLOPLAY:
        //
        currentGameState = getGameStateSoloPlay();
        currentRenderer = &rendrSoloPlay;
        break;
    }
}

void Game::endGame()
{
    window.close();
}

/*  Game::events() doit recuperer les input utilisateurs    */
void Game::events()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        //  Fermeture de la fenêtre
        if (event.type == sf::Event::Closed)
            window.close();
        //  Une touche du clavier est pressee
        else if (event.type == sf::Event::KeyPressed)
            playerInput(event.key.code, true);
        //  Une touche du clavier cesse d'etre pressee
        else if (event.type == sf::Event::KeyReleased)
            playerInput(event.key.code, false);
    }
}

void Game::playerInput(sf::Keyboard::Key k, bool b)
{
    if(k == sf::Keyboard::Up)
        keyboard.setKeyUp(b);
    else if (k == sf::Keyboard::Down)
        keyboard.setKeyDown(b);
    else if (k == sf::Keyboard::Escape)
        keyboard.setKeyEscape(b);
    else if (k == sf::Keyboard::Enter)
        keyboard.setKeyEnter(b);
    else if (k == sf::Keyboard::Space)
        keyboard.setKeySpace(b);
}

/*  Game::update() gere la normalisation du temps, puis demande au current gamestate d'effectuer ses operations */
void Game::update(sf::Time delta)
{
    currentGameState->execute(delta);
}

/*  Game::display() affiche la liste des objets utiles au jeu   */
void Game::display()
{
    //  Premierement, vider l'affichage via un clear()
    window.clear();
    currentRenderer->render(&window);
    window.display();
}

GameSettings* Game::getSettings(){  return &settings;   }

KeyboardControls* Game::getKeyboard(){  return &keyboard;   }

/*  Methodes renvoyant la largeur et la hauteur de fenetre  */
int Game::getWindowHeight(){    return window_height;   }
int Game::getWindowWidth(){     return window_width;    }

/*  Methodes renvoyant les differents etats du jeu  */
GameStateBase* Game::getCurrentGameState(){ return currentGameState;    }
GameStateSoloPlay* Game::getGameStateSoloPlay(){    return &gsSoloPlay; }
GameStateMainMenu* Game::getGameStateMainMenu(){    return &gsMainMenu; }
