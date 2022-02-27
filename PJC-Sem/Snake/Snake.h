//
// Created by ondrej on 15.11.21.
//

#ifndef PJC_CONSOLEGAME_SNAKE_H
#define PJC_CONSOLEGAME_SNAKE_H

class Snake {
private:
    const int width = 30;
    const int height = 15;
    int x,y, fruitx, fruitY;
    int tailX[100], tailY[100];
    int nTAil;
    enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
public:
    int score;
    bool gameOver;
    void setup();
    void draw();
    void input();
    void logic();
};
#endif //PJC_CONSOLEGAME_SNAKE_H
