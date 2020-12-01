#ifndef _KEYBOARDCONTROL_
#define _KEYBOARDCONTROL_

class KeyboardControls
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
            KeyboardControls();
    /*  Methode pour reset les touches pressees */
    void    reset();
    /*  Methodes permettant de recuperer les touches pressees   */
    bool    getKeyUp();
    bool    getKeyDown();
    bool    getKeyEscape();
    bool    getKeyEnter();
    /*  Methodes permettant de definir les touches pressees */
    void    setKeyUp(bool b);
    void    setKeyDown(bool b);
    void    setKeyEscape(bool b);
    void    setKeyEnter(bool b);
/*  ----    VARIABLES   ----    */
private:
    bool    keyUP,
            keyDOWN,
            keyESCAPE,
            keyENTER;
};
#endif // _KEYBOARDCONTROL_
