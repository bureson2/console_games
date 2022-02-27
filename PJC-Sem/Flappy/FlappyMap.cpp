//
// Created by ondrej on 26.12.21.
//

#include <cstdlib>
#include <ctime>
#include "FlappyMap.h"

using namespace std;

FlappyMap::FlappyMap(int width) {
    for(int i = 0; i < width; i++){
        if(i > 20) pipes.push_front(false);
        else if(rand() % 60 < 2) pipes.push_front(true);
        else pipes.push_front(false);
    }
}

void FlappyMap::move() {
    if (rand() % probability < 2) // nastaveni obtiznosti
        pipes.push_back(true);
    else
        pipes.push_back(false);
    pipes.pop_front();
}

bool FlappyMap::checkPosition(int position) {
    return pipes[position];
}

void FlappyMap::setProbability() {
    if(FlappyMap::probability > 15){
        FlappyMap::probability = FlappyMap::probability--;
    }
}
