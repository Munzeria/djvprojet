#include "RendererSoloPlay.h"

#include "Game.h"

RendererSoloPlay::RendererSoloPlay(Game* g):
    Renderer(g),
    font(),
    texGagne(),
    sprGagne(),
    texPerdu(),
    sprPerdu()
    {
        //  Lien avec le gamestate
        linkedState = game->getGameStateSoloPlay();

        //  Ressource police
        font.loadFromFile("FreeMono.ttf");

        //  Chargement images
        texGagne.loadFromFile("img/gagne.png");
        texPerdu.loadFromFile("img/perdu.png");

        texGagne.setSmooth(true);
        texPerdu.setSmooth(true);

        sprGagne.setTexture(texGagne);
        sprPerdu.setTexture(texPerdu);

        sprGagne.setOrigin(100.f, 25.f);
        sprPerdu.setOrigin(100.f, 25.f);

        sprGagne.setPosition(game->getWindowWidth()/2, game->getWindowHeight()/2);
        sprPerdu.setPosition(game->getWindowWidth()/2, game->getWindowHeight()/2);

        //  Initialisation des pointeurs
        playerRacket = linkedState->getPlayerRacket();
        iaRacket = linkedState->getIARacket();
        ball = linkedState->getBall();
        scoreText = linkedState->getScoreText();

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

RendererSoloPlay::~RendererSoloPlay()
{

}

void RendererSoloPlay::render(sf::RenderWindow* window)
{
    //  Si partie terminee, pas d'affichage de la balle
    if (!linkedState->getGameEnded())
        window->draw(*ball);

    window->draw(*playerRacket);
    window->draw(*iaRacket);
    window->draw(*scoreText);

    if (linkedState->getGameEnded())
    {
        //  Si joueur a gagne
        if (linkedState->getScoreDiff() > 0)
            window->draw(sprGagne);
        else
            window->draw(sprPerdu);
    }
    else if(linkedState->getGamePaused())
    {
        //  Affichage pause ?
    }
}
