//
// Created by ondrej on 14.11.21.
//
#include "CTR.h"

#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

CTR::CTR(int numberOfLanes, int width) :
        numberOfLanes(numberOfLanes),
        width(width),
        lifes(3),
        quit(false), score(0){
    for(int i = 0 ; i < numberOfLanes; i++){
        map.push_back(new CTRLane(width));
    }
    player = new CTRPlayer(width);
}

CTR::~CTR() {
    delete player;
    for(int i = 0; i < map.size(); i++){
        CTRLane * current = map.back();
        map.pop_back();
        delete current;
    }
}

void CTR::draw(){
    system("clear");
    for(int i = 0; i < numberOfLanes; i++){
        for(int j = 0; j < width; j++){
            if(player->x == j && player->y == i){cout << "\033[44m\033[34mO\033[0m";}
            else if(i == 0){ cout << "\033[32m\033[42m-\033[0m"; }
            else if(i == numberOfLanes - 1) { cout << "\033[32m\033[42m-\033[0m"; }
            else if(map[i]->checkPosition(j) && i != 0 && i != numberOfLanes-1){cout << "\033[31m\033[41m=\033[0m"; }
            else { cout << "-"; }
        }
        cout << endl;
    }
    cout << "Score: " << score << endl;
}

void CTR::input(){
    if(_kbhit()){
        char current = getch();
        if(current == 'a'){ player->x--; }
        if(current == 'd'){ player->x++; }
        if(current == 'w'){ player->y--; }
        if(current == 's'){ player->y++; }
        if(current == 'x'){ quit = true; }
    }
}

void CTR::logic(){
    for(int i = 1; i < numberOfLanes - 1; i++){
        if(rand() % 10 == 1){ // NOT SRAND
            map[i]->move();
        }
        if(map[i]->checkPosition(player->x) && player->y == i){
            lifes--;
            if(lifes == 0){
                quit = true;
            }
            player->x = width / 2;
            player->y = 0;
            // uloz skore
        }
    }
    if(player-> y == numberOfLanes - 1){
        score += 10;
        player-> y = 0;
        cout << "\x07";
        for(int i = 1; i < numberOfLanes - 1; i++){
            map[i]->changeDIrection();
        }
    }
}

bool CTR::run(){
    while (!quit){
        //srand(time(NULL));
        input();
        logic();
        draw();
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}
