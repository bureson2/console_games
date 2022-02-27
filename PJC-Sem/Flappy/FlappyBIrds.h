//
// Created by ondrej on 26.12.21.
//

#ifndef FLAPPY_FLAPPYBIRDS_H
#define FLAPPY_FLAPPYBIRDS_H

#include <vector>
#include "Bird.h"
#include "FlappyMap.h"

using namespace std;

class FlappyBIrds {
private:
    bool quit;
    int numberOfLanes;
    int width;
    int score;
    int lifes;
    Bird * bird;
    vector<FlappyMap *> map;
public:
    FlappyBIrds(int numberOfLanes, int width);
    ~FlappyBIrds();
    void draw();
    void input();
    void logic();
    bool run();
};

#endif //FLAPPY_FLAPPYBIRDS_H
