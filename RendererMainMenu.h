/*  Developpement de jeux vidéos - Projet
**  Space Pong
**  ----------
**  Classe heritant de Renderer
**  cette classe gere l'affichage du menu principal */
#ifndef _RENDERERMAINMENU_
#define _RENDERERMAINMENU_

#include "Renderer.h"

//  Forward declaration
class GameStateMainMenu;

class RendererMainMenu: public Renderer
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
    RendererMainMenu(Game* g);
    /*  Constructeur copie, indisponible    */
    RendererMainMenu(const RendererMainMenu &rmm) = delete;
    /*  Destructeur */
    virtual ~RendererMainMenu();
    /*  Operateur affectation, indisponible */
    RendererMainMenu& operator=(const RendererMainMenu &rmm) = delete;
    /*  override de render()    */
    void render(sf::RenderWindow* window) override;
/*  ----    VARIABLES   ----    */
private:
    GameStateMainMenu*  linkedState;
    //  Fond d'ecran menu
    sf::Texture         mainMenuBckgrd;
    sf::Sprite          mainMenuBackSprite;
    //  Bouton Jouer
    sf::Texture         texJouer;
    sf::Sprite          sprJouer;
    //  Bouton quitter
    sf::Texture         texQuitter;
    sf::Sprite          sprQuitter;
    //  Effet selection/deselection
    sf::Color           selected,
                        passive;
};
#endif // _RENDERERMAINMENU_
