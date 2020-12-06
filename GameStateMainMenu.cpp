#include "GameStateMainMenu.h"

#include "Game.h"

//  Constructeur
GameStateMainMenu::GameStateMainMenu(Game* g):
    GameStateBase(g),
    selection(0),
    totalChoice(2),
    lastButtonCheck(),
    delay()
    {
        lastButtonCheck = sf::seconds(0.f);
        delay = sf::seconds(0.25f);
    }

GameStateMainMenu::~GameStateMainMenu()
{
    //  Le destructeur de GameStateBase sera appele par defaut, aucun autre pointeur a delete
}

void GameStateMainMenu::execute(sf::Time delta)
{
    //  Si assez de temps a passe depuis le dernier check des inputs
    lastButtonCheck += delta;
    if (lastButtonCheck >= delay)
    {
        if (getGame()->getKeyboard()->getKeyUp())
        {
            selection = std::max(selection-1, 0);
            lastButtonCheck = sf::seconds(0.);
        }
        else if (getGame()->getKeyboard()->getKeyDown())
        {
            selection = std::min(selection+1, totalChoice-1);
            lastButtonCheck = sf::seconds(0.);
        }
        else if (getGame()->getKeyboard()->getKeyEnter())
        {
            switch(selection)
            {
            case 0:
                //  JOUER
                getGame()->getGameStateSoloPlay()->resetGame();
                getGame()->switchGameState(Game::SOLOPLAY);
                return;
            case 1:
                //  QUITTER
                getGame()->endGame();
            }

        }
    }
}

int GameStateMainMenu::getCurrentChoice(){  return selection;   }
