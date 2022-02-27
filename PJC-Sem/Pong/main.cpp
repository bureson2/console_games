#include <iostream>
#include <time.h>
#include <thread>
#include "Ball.h"
#include "Paddle.h"
#include "Pong.h"

using namespace std;

int main() {
    Pong game(40,20);
    game.run();

    return 0;
}
