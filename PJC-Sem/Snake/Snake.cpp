//
// Created by ondrej on 15.11.21.
//
#include "Snake.h"

#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

void Snake::setup(){
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Snake::draw(){
    system("clear");
    for(int i = 0; i < width; i++){
        cout << "\033[33m\033[43m#\033[0m";
    }
    cout << endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if (j == 0 || j == width-1) { cout << "\033[33m\033[43m#\033[0m"; }
            else if( i == y && j == x){ cout << "\033[35m\033[45mO\033[0m"; }
            else if(i == fruitY && j == fruitx) {
                cout << "\033[31m\033[41mX\033[0m";
            }
            else {
                bool print = false;
                for(int k = 0; k < nTAil; k++){
                    if(tailX[k] == j && tailY[k] == i){
                        cout << "\033[35mo\033[0m";
                        print = true;
                    }
                }
                if(!print){
                    cout << "\033[42m \033[0m";
                }
            }
        }
        cout << endl;
    }

    for(int i = 0; i < width; i++){
        cout << "\033[33m\033[43m#\033[0m";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Snake::input(){
    if(_kbhit()){
        switch (getch()) {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                cout << "GAME OVER";
                break;
        }
    }
}

void Snake::logic(){
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i = 1; i < nTAil; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir){
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if(x >= width-1) x = 1; else if(x <= 0) x = width - 2;
    if(y >= height) y = 0; else if(y < 0) y = height - 1;

    for(int i = 0; i < nTAil; i++){
        if (tailX[i] == x && tailY[i] == y) gameOver = true;
    }

    if(x == fruitx && y == fruitY){
        score += 10;
        fruitx = rand() % width + 1;
        fruitY = rand() % height;
        nTAil++;
        cout << fruitx << " : " << fruitY;
    }
}

