#ifndef _KEYBOARDCONTROL_
#define _KEYBOARDCONTROL_

class KeyboardControls
{
/*  ----    METHODES    ----    */
public:
    /*  Constructeur    */
            KeyboardControls();
    /*  Constructeur copie. Classe sans pointeurs, default suffit   */
            KeyboardControls(const KeyboardControls &kbc) = default;
    /*  Destructeur, default suffit */
            ~KeyboardControls() = default;
    /*  Operateur d'affectation, default suffit */
    KeyboardControls& operator=(const KeyboardControls &kbc) = default;
    /*  Methode pour reset les touches pressees */
    void    reset();
    /*  Methodes permettant de recuperer les touches pressees   */
    bool    getKeyUp();
    bool    getKeyDown();
    bool    getKeyEscape();
    bool    getKeyEnter();
    bool    getKeySpace();
    /*  Methodes permettant de definir les touches pressees */
    void    setKeyUp(bool b);
    void    setKeyDown(bool b);
    void    setKeyEscape(bool b);
    void    setKeyEnter(bool b);
    void    setKeySpace(bool b);
/*  ----    VARIABLES   ----    */
private:
    bool    keyUP,
            keyDOWN,
            keyESCAPE,
            keyENTER,
            keySPACE;
};
#endif // _KEYBOARDCONTROL_
