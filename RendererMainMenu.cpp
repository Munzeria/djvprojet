#include "RendererMainMenu.h"

#include "Game.h"

#include <iostream>

//  Constructeur
RendererMainMenu::RendererMainMenu(Game* g):
    Renderer(g),
    mainMenuBckgrd(),
    mainMenuBackSprite(),
    texJouer(),
    sprJouer(),
    texQuitter(),
    sprQuitter(),
    selected(255, 255, 255, 255),
    passive(210, 210, 210, 192)
    {
        //  Lien avec le gamestate
        linkedState = game->getGameStateMainMenu();
        //  Fond d'ecran
        mainMenuBckgrd.loadFromFile("img/mainmenu.jpeg");
        mainMenuBackSprite.setTexture(mainMenuBckgrd);
        //  Boutons
        texJouer.loadFromFile("img/jouer.png");
        texQuitter.loadFromFile("img/quitter.png");
        //  Lissage
        texJouer.setSmooth(true);
        texQuitter.setSmooth(true);

        sprJouer.setTexture(texJouer);
        sprQuitter.setTexture(texQuitter);

        sprJouer.setScale(0.35, 0.35);
        sprQuitter.setScale(0.35, 0.35);

        sprJouer.setOrigin(sprJouer.getGlobalBounds().width/2, sprJouer.getGlobalBounds().height/2);
        sprQuitter.setOrigin(sprQuitter.getGlobalBounds().width/2, sprQuitter.getGlobalBounds().height/2);

        sprJouer.setPosition(game->getWindowWidth() - sprJouer.getGlobalBounds().width,
                             game->getWindowHeight() - sprJouer.getGlobalBounds().height - sprQuitter.getGlobalBounds().height);
        sprQuitter.setPosition(game->getWindowWidth() - sprQuitter.getGlobalBounds().width,
                               game->getWindowHeight() - sprQuitter.getGlobalBounds().height);
    }

void RendererMainMenu::render(sf::RenderWindow* window)
{
    window->draw(mainMenuBackSprite);

    switch(linkedState->getCurrentChoice())
    {
    case 0:
        //  JOUER est choisi
        sprJouer.setColor(selected);
        sprQuitter.setColor(passive);
        break;
    case 1:
        //  QUITTER est choisi
        sprQuitter.setColor(selected);
        sprJouer.setColor(passive);
        break;
    }

    window->draw(sprJouer);
    window->draw(sprQuitter);
}
