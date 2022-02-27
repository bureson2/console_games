//
// Created by ondrej on 18.12.21.
//

#ifndef PONG_PONG_H
#define PONG_PONG_H


#include "Ball.h"
#include "Paddle.h"

class Pong {
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool quit;
    int helper;
    Ball * ball;
    Paddle *player1;
    Paddle *player2;
public:
    Pong(int w, int h);
    ~Pong();
    void scoreUp(Paddle * player);
    void draw();
    void input();
    void logic();
    void run();
};


#endif //PONG_PONG_H
