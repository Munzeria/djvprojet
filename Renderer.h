#ifndef _RENDERER_
#define _RENDERER_

#include <SFML/Graphics.hpp>

class Game;

class Renderer
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
    Renderer(Game *g);
    /*  render() se charge d'afficher les elements specifiques a un gamestate.
    **  virtual pure, car Renderer doit etre abstrait.  */
    virtual void render(sf::RenderWindow* window) = 0;
/*  ----    VARIABLES   ----    */
protected:
    Game* game; //  Les classes redéfinissant Renderer auront besoin de la reference a Game
};
#endif // _RENDERER_
