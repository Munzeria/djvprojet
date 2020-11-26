#ifndef _RENDERERSOLOPLAY_
#define _RENDERERSOLOPLAY_

#include "Renderer.h"

//  Forward declaration
class GameStateSoloPlay;

/*  Cette classe va se specialiser dans l'affichage de l'etat SoloPlay  */
class RendererSoloPlay: public Renderer
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
    RendererSoloPlay(Game* g);
    /*  override de render()    */
    void render(sf::RenderWindow* window) override;
/*  ----    VARIABLES   ----    */
private:
    GameStateSoloPlay* linkedState;
    /*  Elements a dessiner */
    sf::RectangleShape* playerRacket,
                        *iaRacket;
    sf::CircleShape*    ball;
};
#endif // _RENDERERSOLOPLAY_
