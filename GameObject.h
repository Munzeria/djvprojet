/*  Un GameObject représente n'importe quel élément du jeu.
**  Dans le cas spécifique de Space Pong, il sera prévu d'avoir:
**  ->  La balle
**  ->  Deux "raquettes"
**  ->  Les bords du terrain
*/
#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include <SFML/Graphics.hpp>

class GameObject
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
            GameObject(sf::Drawable* draw);
    /*  Renvoie l'element drawable representant cet objet   */
    sf::Drawable*    getDrawable();

/*  ----    VARIABLES   ----    */
private:
    sf::Drawable*    drawableElement;
};
#endif // _GAMEOBJECT_
