//
// Created by ondrej on 14.11.21.
//
#ifndef PJC_CONSOLEGAME_CTR_H
#define PJC_CONSOLEGAME_CTR_H

#include "CTRPlayer.h"
#include "CTRLane.h"

#include <vector>

class CTR {
private:
    bool quit;
    int numberOfLanes;
    int width;
    int score;
    int lifes;
    CTRPlayer *player;
    vector<CTRLane *> map;
public:
    CTR(int numberOfLanes, int width);
    ~CTR();
    void draw();
    void input();
    void logic();
    bool run();
};
#endif //PJC_CONSOLEGAME_CTR_H
