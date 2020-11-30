#ifndef _GAMESETTINGS_
#define _GAMESETTINGS_

/*  GameSettings va contenir les informations relative au jeu, de manière "globale"
**  telles que la taille des raquettes, la vitesse des raquettes et de la balle
*/
class GameSettings
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
    GameSettings();
    /*  Getters */
    int getRacketWidth();
    int getRacketHeight();
    int getRacketSpeed();
/*  ----    VARIABLES   ----    */
private:
    //  Largeur et hauteur des raquettes
    int racketWidth,
        racketHeight,
        racketSpeed;
};
#endif // _GAMESETTINGS_

