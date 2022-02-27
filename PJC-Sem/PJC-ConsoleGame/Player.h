//
// Created by ondrej on 26.12.21.
//

#ifndef PJC_CONSOLEGAME_PLAYER_H
#define PJC_CONSOLEGAME_PLAYER_H


class Player {
private:
    int posX;
    int posY;
    char skin = 'X';
    char availableSkins[5] = {'X','O','$','@', '%'};
public:
    enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir = STOP;

    Player(const int posX, const int posY);

    int getPosX();
    int getPosY();

    void changePosX(int value);
    void changePosY(int value);

    char getSkin() const;

    void setSkin(int skinNumber);

    virtual ~Player();

    eDirection getDir() const;

    void setDir(eDirection dir);
};



#endif //PJC_CONSOLEGAME_PLAYER_H
