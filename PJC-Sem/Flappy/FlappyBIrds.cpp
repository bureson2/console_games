//
// Created by ondrej on 26.12.21.
//

#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

#include "FlappyBIrds.h"

FlappyBIrds::FlappyBIrds(int numberOfLanes, int width) :
        numberOfLanes(numberOfLanes),
        width(width),
        lifes(3),
        quit(false), score(0){
    for(int i = 0; i < numberOfLanes; i++){
        map.push_back(new FlappyMap(width));
    }
    bird = new Bird(numberOfLanes / 2);
}

FlappyBIrds::~FlappyBIrds() {
    delete bird;
    for(int i = 0; i < map.size(); i++){
        FlappyMap * current = map.back();
        map.pop_back();
        delete current;
    }
}

void FlappyBIrds::draw() {
    system("clear");
    for(int i = 0; i < numberOfLanes; i++){
        for(int j = 0; j < width; j++){
            if(map[i]->checkPosition(j) && i != numberOfLanes){
                cout << "\033[30m\033[47m#\033[0m";
            } else if(bird->x == i && j == 2){
                cout << "\033[30m\033[43mO\033[0m";
            } else {
                cout << "\033[44m \033[0m";
            }
        }
        cout << endl;
    }
    for(int i = 0; i < width; i++){
        cout << "\033[42m#\033[0m";
    }
    cout << endl << "Score: " << score << endl;
    cout << endl << "Lifes: " << lifes << endl;
}

void FlappyBIrds::input() {
    if(_kbhit()){
        char current = getch();
        if(current == 'w' && bird->x > 1){
            int move = bird->x - 2;
            bird-> x = move; }
        if(current == 'x'){ quit = true; }
    }
}

void FlappyBIrds::logic() {
    for(int i = 0; i < numberOfLanes; i++){
        map[i]->move();
        if(i == bird->x && map[i]->checkPosition(2)){
            lifes--;
            if(lifes == 0){
                quit = true;
            }
            bird->x = numberOfLanes / 2;
        }
    }
}

bool FlappyBIrds::run() {
    int gravity = 0;
    while (!quit){
        if(gravity % 3 == 0 && bird->x < numberOfLanes - 1){
            bird->x++;
        }
        if(gravity % 10 == 0){
            for(int i = 0; i < numberOfLanes; i++){
                map[i]->setProbability();
            }
        }
        gravity++;
        input();
        logic();
        draw();
        this_thread::sleep_for(chrono::milliseconds(100));
        score++;
    }
}

