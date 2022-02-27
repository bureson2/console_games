//
// Created by ondrej on 14.11.21.
//
#ifndef PJC_CONSOLEGAME_CTRLANE_H
#define PJC_CONSOLEGAME_CTRLANE_H

#include <deque>

class CTRLane {
private:
    std::deque<bool> cars;
    bool right;
public:
    CTRLane(int width);
    void move();
    bool checkPosition(int position);
    void changeDIrection();
};
#endif //PJC_CONSOLEGAME_CTRLANE_H
