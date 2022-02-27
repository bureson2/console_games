//
// Created by ondrej on 26.12.21.
//

#ifndef PJC_CONSOLEGAME_MENU_H
#define PJC_CONSOLEGAME_MENU_H


#include "Player.h"

class Menu {
private:
    const int width = 30;
    const int height = 15;
    Player player = Player(width/2, height/2);
    void startGame(int x, int y);
public:
    virtual ~Menu();
    int gamePoints = 0;
    bool gameOver = false;
    bool draw();
    bool input();
    void logic();
};


#endif //PJC_CONSOLEGAME_MENU_H
