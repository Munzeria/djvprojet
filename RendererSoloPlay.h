/*  Developpement de jeux vidéos - Projet
**  Space Pong
**  ----------
**  Classe heritant de Renderer
**  Cette classe gere l'affichage du jeu en solo */
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
    /*  Constructeur copie, desactive   */
    RendererSoloPlay(const RendererSoloPlay &rsp) = delete;
    /*  Destructeur */
    virtual ~RendererSoloPlay();
    /*  Operateur affectation, desactive    */
    RendererSoloPlay& operator=(const RendererSoloPlay &rsp) = delete;
    /*  override de render()    */
    void render(sf::RenderWindow* window) override;
/*  ----    VARIABLES   ----    */
private:
    GameStateSoloPlay* linkedState;
    /*  Elements a dessiner */
    sf::RectangleShape* playerRacket,
                        *iaRacket;
    sf::CircleShape*    ball;
    sf::Text*           scoreText;
    sf::Font            font;
    //  image GAGNE
    sf::Texture         texGagne;
    sf::Sprite          sprGagne;
    //  Image PERDU
    sf::Texture         texPerdu;
    sf::Sprite          sprPerdu;
};
#endif // _RENDERERSOLOPLAY_
