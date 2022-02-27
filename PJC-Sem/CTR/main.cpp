#include <iostream>
#include "CTR.h"

using namespace std;

int main() {

    CTR game = CTR(12, 60);
    game.run();
    cout << "GAME OVER!" << endl;


    return 0;
}
