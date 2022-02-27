#include <iostream>
#include "FlappyBIrds.h"

using namespace std;

int main() {

    FlappyBIrds game = FlappyBIrds(12,60);
    game.run();
    cout << "GAME OVER!" << endl;

    return 0;
}
