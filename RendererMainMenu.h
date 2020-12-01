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
