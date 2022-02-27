//
// Created by ondrej on 18.12.21.
//

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <iostream>
using namespace std;


class Paddle {
private:
    int x, y;
    int originalX, originalY;
public:
    Paddle(int posX, int posY);
    inline void reset(){ x = originalX; y = originalY; }
    inline int getX(){ return x; }
    inline int getY(){ return y; }
    inline void moveUp(){ y--; }
    inline void moveDown(){ y++; }
    friend ostream & operator<<(ostream & o, Paddle c){
        o << "Paddle [" << c.x << "," << c.y << "]" << endl;
        return o;
    }
};


#endif //PONG_PADDLE_H
