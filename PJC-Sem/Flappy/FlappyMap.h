//
// Created by ondrej on 26.12.21.
//

#ifndef FLAPPY_FLAPPYMAP_H
#define FLAPPY_FLAPPYMAP_H


#include <deque>

class FlappyMap {
private:
    std::deque<bool> pipes;
    int probability = 60;
public:
    FlappyMap(int width);
    void move();
    bool checkPosition(int position);

    void setProbability();
};


#endif //FLAPPY_FLAPPYMAP_H
