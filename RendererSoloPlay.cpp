#include "RendererSoloPlay.h"

#include "Game.h"
#include <iostream>

RendererSoloPlay::RendererSoloPlay(Game* g):
    Renderer(g),
    font()
    {
        //  Ressource police
        font.loadFromFile("FreeMono.ttf");
        //  Initialisation des pointeurs
        playerRacket = g->getGameStateSoloPlay()->getPlayerRacket();
        iaRacket = g->getGameStateSoloPlay()->getIARacket();
        ball = g->getGameStateSoloPlay()->getBall();
        scoreText = g->getGameStateSoloPlay()->getScoreText();
        //  Mise en place de l'affichage - raquette du joueur
        playerRacket->setSize(sf::Vector2f(g->getSettings()->getRacketWidth(), g->getSettings()->getRacketHeight()));
        playerRacket->setFillColor(sf::Color::Red);
        //  Raquette IA
        iaRacket->setSize(sf::Vector2f(g->getSettings()->getRacketWidth(), g->getSettings()->getRacketHeight()));
        iaRacket->setFillColor(sf::Color::Blue);
        //  Balle
        ball->setRadius(g->getSettings()->getBallRadius());
        ball->setFillColor(sf::Color::Yellow);
        //  Texte
        scoreText->setFont(font);
        scoreText->setCharacterSize(30);
        scoreText->setStyle(sf::Text::Regular);
        scoreText->setPosition(g->getWindowWidth()/2 - 50, 10);
        scoreText->setFillColor(sf::Color::White);
    }

void RendererSoloPlay::render(sf::RenderWindow* window)
{
    window->draw(*ball);
    window->draw(*playerRacket);
    window->draw(*iaRacket);
    window->draw(*scoreText);
}
