/*  Developpement de jeux vidéos - Projet
**  Space Pong
**  ----------
**  Classe ABSTRAITE
**  Les classes Renderer auront pour tache de gerer l'affichage du jeu
**  Les classes Renderer seront specialisees pour un etat particulier   */
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
    /*  Constructeur copie, indisponible    */
    Renderer(const Renderer &r) = delete;
    /*  Destructeur */
    virtual ~Renderer();
    /*  Operateur affectation, indisponible */
    Renderer& operator=(const Renderer &r) = delete;
    /*  render() se charge d'afficher les elements specifiques a un gamestate.
    **  virtual pure, car Renderer doit etre abstrait.  */
    virtual void render(sf::RenderWindow* window) = 0;
/*  ----    VARIABLES   ----    */
protected:
    Game* game; //  Les classes redéfinissant Renderer auront besoin de la reference a Game
};
#endif // _RENDERER_
