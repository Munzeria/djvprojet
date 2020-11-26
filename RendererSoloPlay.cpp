#include "RendererSoloPlay.h"

#include "Game.h"
#include <iostream>

RendererSoloPlay::RendererSoloPlay(Game* g):
    Renderer(g)
    {
        //  Initialisation des pointeurs
        playerRacket = g->getGameStateSoloPlay()->getPlayerRacket();
        iaRacket = g->getGameStateSoloPlay()->getIARacket();
        ball = g->getGameStateSoloPlay()->getBall();
        //  Mise en place de l'affichage - raquette du joueur
        playerRacket->setSize(sf::Vector2f(25, 100));
        playerRacket->setFillColor(sf::Color::Red);
        //  Raquette IA
        iaRacket->setSize(sf::Vector2f(25, 100));
        iaRacket->setFillColor(sf::Color::Blue);
        //  Balle
        ball->setRadius(10);
        ball->setFillColor(sf::Color::Yellow);
    }

void RendererSoloPlay::render(sf::RenderWindow* window)
{
    window->draw(*playerRacket);
    window->draw(*iaRacket);
    window->draw(*ball);
}
