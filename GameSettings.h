/*  Developpement de jeux vidéos - Projet
**  Space Pong
**  ----------
**  Classe de parametres centralisant differents elements parametrables du jeu via code
**  tels que vitesse, taille, des raquettes et de la balle */
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
    /*  Constructeur de copie   */
    GameSettings(const GameSettings &gs);
    /*  Destructeur - aucun pointeur dans cette classe, le destructeur par défaut suffit    */
    ~GameSettings() = default;
    /*  Operateur d'affectation */
    GameSettings& operator=(const GameSettings &gs);
    /*  Getters */
    int getRacketWidth();
    int getRacketHeight();
    int getRacketSpeed();
    int getBallRadius();
    int getBallSpeed();
/*  ----    VARIABLES   ----    */
private:
    //  Largeur et hauteur des raquettes
    int racketWidth,
        racketHeight,
        racketSpeed,
        ballRadius,
        ballSpeed;
};
#endif // _GAMESETTINGS_

