//
// Created by ondrej on 18.12.21.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <iostream>

using namespace std;

enum eDir { STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3,
    RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class Ball {
private:
    int x, y;
    int originalX, originalY;
    eDir direction;
public:
    Ball(int posX, int posY);
    void Reset();
    void changeDirection(eDir d);
    void randomDirection();
    inline int getX(){ return x;}
    inline int getY(){ return y;}
    inline eDir getDirection(){ return direction;}
    void move();
    //help function
    friend ostream & operator<<(ostream & o, Ball c){
        o << "BAll [" << c.x << "," << c.y << "][" << c.direction << "]" << endl;
        return o;
    }
};


#endif //PONG_BALL_H
