//
// Created by ondrej on 18.12.21.
//

#include <thread>
#include <conio.h>
#include "Pong.h"

Pong::Pong(int w, int h){
    helper = 0;
    srand(time(NULL));
    quit = false;
    up1 = 'w'; up2 = 'i';
    down1 = 's'; down2 = 'k';
    score1 = score2 = 0;
    width = w; height = h;
    ball = new Ball(w/2, h/2);
    player1 = new Paddle(1, h/2 - 3);
    player2 = new Paddle(w - 2, h / 2 - 3);
}

Pong::~Pong(){
    delete ball, player1, player2;
}

void Pong::scoreUp(Paddle * player){
    if(player == player1){
        score1++;
    } else {
        score2++;
    }
    ball->Reset();
    player1->reset();
    player2->reset();
}

void Pong::draw(){
    system("clear");
    for (int i = 0; i < width + 2; i++){
        cout << "\033[47m\033[37m#\033[0m";
    }
    cout << endl;

    for (int i = 0; i < height; i++){
        for(int j =0; j < width; j++){
            int ballX = ball->getX();
            int ballY = ball->getY();
            int player1x = player1->getX();
            int player1y = player1->getY();
            int player2x = player2->getX();
            int player2y = player2->getY();

            if(j == 0) cout << "\033[47m\033[37m#\033[0m";

            if(ballX == j && ballY == i){
                cout << "O";
            } else if (player1x == j && player1y == i){
                cout << "\033[44m\033[34mX\033[0m";
            } else if (player1x == j && player1y + 1 == i){
                cout << "\033[44m\033[34mX\033[0m";
            } else if (player1x == j && player1y + 2 == i){
                cout << "\033[44m\033[34mX\033[0m";
            } else if (player1x == j && player1y + 3 == i){
                cout << "\033[44m\033[34mX\033[0m";
            } else if (player2x == j && player2y == i){
                cout << "\033[41m\033[31mX\033[0m";
            } else if (player2x == j && player2y + 1 == i){
                cout << "\033[41m\033[31mX\033[0m";
            } else if (player2x == j && player2y + 2 == i){
                cout << "\033[41m\033[31mX\033[0m";
            } else if (player2x == j && player2y + 3 == i){
                cout << "\033[41m\033[31mX\033[0m";
            } else cout << " ";

            if(j == width - 1) cout << "\033[47m\033[37m#\033[0m";

        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++){
        cout << "\033[47m\033[37m#\033[0m";
    }
    cout << endl;
    cout << score1 << " : " << score2 << endl;
}

void Pong::input(){
    ball -> move();

    int player1y = player1->getY();
    int player2y = player2->getY();

    if(_kbhit()){
        char current = getch();
        if(current == up1){
            if(player1y > 0){
                player1->moveUp();
            }
        }
        if(current == up2){
            if(player2y > 0){
                player2->moveUp();
            }
        }
        if(current == down1){
            if(player1y + 4 < height){
                player1->moveDown();
            }
        }
        if(current == down2){
            helper += 10;
            if(player2y + 4 < height){
                player2->moveDown();
                helper++;
            }
        }

        if(ball->getDirection() == STOP){
            ball->randomDirection();
        }

        if(current == 'x' || current == 'X'){
            quit = true;
        }
    }
}

void Pong::logic(){
    int ballX = ball->getX();
    int ballY = ball->getY();
    int player1x = player1->getX();
    int player1y = player1->getY();
    int player2x = player2->getX();
    int player2y = player2->getY();

    // left paddle
    for(int i = 0; i < 4; i++){
        if(ballX == player1x + 1){
            if(ballY == player1y + i){
                ball->changeDirection((eDir)((rand() % 3) + 4));
            }
        }
    }

    // right paddle
    for(int i = 0; i < 4; i++){
        if(ballX == player2x - 1){
            if(ballY == player2y + i){
                ball->changeDirection((eDir)((rand() % 3) + 1));
            }
        }
    }

    //bottom wall
    if(ballY == height - 1){
        ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
    }

    //top wall
    if(ballY == 0){
        ball->changeDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
    }

    // right wall
    if(ballX == width - 1){
        scoreUp(player1);
    }

    //left wall
    if(ballX == 0){
        scoreUp(player2);
    }
}

void Pong::run(){
    int speedChanger = 0;
    int speedTImer = 150;
    while (!quit){
        draw();
        input();
        logic();
        this_thread::sleep_for(chrono::milliseconds(speedTImer));
        if(speedChanger % 30 == 0){
            speedTImer -= 2;
        }
        speedChanger++;
    }
}
