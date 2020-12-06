/*  Developpement de jeux vidéos - Projet
**  Space Pong
**  ----------
**  Classe heritant de GameStateBase.
**  Gere le comportement du jeu dans le menu principal  */
#ifndef _GAMESTATEMAINMENU_
#define _GAMESTATEMAINMENU_

#include "GameStateBase.h"

class GameStateMainMenu: public GameStateBase
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
    GameStateMainMenu(Game* g);
    /*  Operateur de copie, indisponible    */
    GameStateMainMenu(const GameStateMainMenu &gsmm) = delete;
    /*  Destructeur */
    virtual ~GameStateMainMenu();
    /*  Operateur d'affectation, indisponible   */
    GameStateMainMenu& operator=(const GameStateMainMenu &gsmm) = delete;
    /*  Methode override; voir GameStateBase.h  */
    void execute(sf::Time delta) override;
    /*  Recuperer le choix actuel   */
    int getCurrentChoice();
/*  ----    VARIABLES   ----    */
private:
    int     selection,
            totalChoice;
    //  Un leger delai sera mis en place pour eviter de parcourir trop vite les choix du menu
    sf::Time    lastButtonCheck,
                delay;
};
#endif // _GAMESTATEMAINMENU_
