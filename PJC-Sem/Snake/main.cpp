#include <iostream>

#include "Snake.h"
#include <thread>

using namespace std;

int main() {

    Snake game = Snake();
    game.setup();
    int speed = 250;

    while(!game.gameOver){
        game.draw();
        game.input();
        game.logic();
        this_thread::sleep_for(chrono::milliseconds(speed - game.score));
    }

    return 0;
}
