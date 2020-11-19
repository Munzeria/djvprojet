/*  Developpement de jeux vidéos - Projet
**  Space Pong
**  ----------
**  Classe Game destinee a etre le contenant des autres elements du jeu */
#ifndef _GAME_
#define _GAME_

class Game
{
private:
    /*      events() gerera les evenements tels que input clavier/souris, fermeture du jeu  */
    void    events();
    /*      update() servira a appeller la fonction update() du GameState actuel
    **      update aura aussi pour tache de gerer la normalisation du temps par frame   */
    void    update();

public:
    /*      Constructeur    */
            Game();
    /*      run() sert a lancer la boucle principale du jeu */
    void    run();
};
#endif // _GAME_
