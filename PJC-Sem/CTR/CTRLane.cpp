//
// Created by ondrej on 14.11.21.
//
#include "CTRLane.h"

#include <cstdlib>
#include <time.h>

using namespace std;

CTRLane::CTRLane(int width)
{
    for (int i = 0; i < width; i++) {
        if (rand() % 10 < 2) // nastaveni obtiznosti
            cars.push_front(true);
        else
            cars.push_front(false);
    }
    right = rand() % 2;
}

void CTRLane::move(){
    srand (time(NULL));
    if(right){
        if (rand() % 10 < 2) // nastaveni obtiznosti
            cars.push_front(true);
        else
            cars.push_front(false);
        cars.pop_back();
    } else {
        if (rand() % 10 < 2) // nastaveni obtiznosti
            cars.push_back(true);
        else
            cars.push_back(false);
        cars.pop_front();
    }

}

// X position
bool CTRLane::checkPosition(int position) {
    return cars[position];
}

void CTRLane::changeDIrection(){
    right = !right;
}
