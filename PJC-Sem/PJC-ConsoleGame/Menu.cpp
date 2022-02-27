//
// Created by ondrej on 26.12.21.
//

#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <thread>

#include "Menu.h"

using namespace std;

enum eDirection{ STOP = 0, LEFT, RIGHT, UP, DOWN};


bool Menu::draw() {
    system("clear");
    for(int i = 0; i < width; i++){
        cout << "\033[43m\033[30m#\033[0m";;
    } cout << endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(j==0 || j == width-1) cout << "\033[43m\033[30m#\033[0m";
            else if(i == 1 && j == 2) cout << "\033[30m\033[44mA\033[0m";
            else if(i == 1 && j == width - 3) cout << "\033[30m\033[44mB\033[0m";
            else if(i == height - 2 && j == 2) cout << "\033[30m\033[44mC\033[0m";
            else if(i == height - 2 && j == width - 3) cout << "\033[30m\033[44mD\033[0m";
            else if(i == height / 2 + 1 && j == width / 2 + 1) cout << "\033[31m\033[41m*\033[0m";
            else if(player.getPosX() == j && player.getPosY() == i) cout << player.getSkin();
            else if(i == 6 && j == 6) cout << "\033[30m\033[44mE\033[0m";
            else cout << "\033[42m \033[0m";
        }
        cout << endl;
    }


    for(int i = 0; i < width; i++){
        cout << "\033[43m\033[30m#\033[0m";;
    }
}

bool Menu::input() {
    if(_kbhit()){
        startGame(player.getPosX(), player.getPosY());
        switch (getch()) {
            case 'a':
                player.setDir(static_cast<Player::eDirection>(LEFT));
                break;
            case 'd':
                player.setDir(static_cast<Player::eDirection>(RIGHT));
                break;
            case 'w':
                player.setDir(static_cast<Player::eDirection>(UP));
                break;
            case 's':
                player.setDir(static_cast<Player::eDirection>(DOWN));
                break;
            case 'x':
                gameOver = true;
                cout << "GAME OVER";
                break;
        }
    }
}

void Menu::logic() {
    startGame(player.getPosX(), player.getPosY());

    switch (player.getDir()) {
        case LEFT:
            if(player.getPosX() > 1){
                player.changePosX(-1);
            }
            break;
        case RIGHT:
            if(player.getPosX() < width-2){
                player.changePosX(+1);
            }
            break;
        case UP:
            if(player.getPosY() > 0){
                player.changePosY(-1);
            }
            break;
        case DOWN:
            if(player.getPosY() < height-1){
                player.changePosY(+1);
            }
            break;
        default:
            break;
    }
}

void Menu::startGame(int x, int y) {
    if(y == 1 && x == 2) std::system("./games/CTR");
    else if(y == 1 && x == width - 3) std::system("./games/Pong");
    else if(y == height - 2 && x == 2) std::system("./games/Ships");
    else if(y == height - 2 && x == width - 3) std::system("./games/Snake");
    else if(y == 6 && x == 6) std::system("./games/FlappyBird");
    else if(y == height / 2 + 1 && x == width / 2 + 1) player.setSkin(std::rand() % 5);
}

Menu::~Menu() {

}
