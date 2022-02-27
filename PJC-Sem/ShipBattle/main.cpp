#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

const int rows = 5;
const int columns = 5;
int matrixComputer[rows][columns];
int matrixPlayer[rows][columns];
int matrixMap[rows][columns];
const int maxShips = 5;
int numberOfPlayersShips = maxShips;
int numberOfCOmputerShips = maxShips;

void clear(){
    for(int i =0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrixComputer[i][j] = 0;
            matrixPlayer[i][j] = 0;
            matrixMap[i][j] = 0;
        }
    }
}

void showBattlePlan(){
    for(int i =0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(matrixMap[i][j] == 2) cout << "\033[37m\033[44m " << "*" << " \033[0m";
            else if(matrixMap[i][j] == 3) cout << "\033[31m\033[44m " << "X" << " \033[0m";
            else cout << "\033[30m\033[44m " << matrixMap[i][j] << " \033[0m";
        }
        cout << endl;
    }
}

void showYourMAp(){
    for(int i =0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(matrixPlayer[i][j] == 1) cout << "\033[32m\033[44m " << "X" << " \033[0m";
            else cout << "\033[30m\033[44m " << matrixPlayer[i][j] << " \033[0m";
        }
        cout << endl;
    }
}

void setComputerShips(){
    int ships = 0;
    while ( ships < maxShips){
        int x = rand() % rows;
        int y = rand() % columns;
        if(matrixComputer[x][y] != 1){
            matrixComputer[x][y] = 1;
            ships++;
        }
    }
}

void setPlayerShip(){
    int ships = 0;
    int x; int y;
    while ( ships < maxShips){
        system("clear");
        cout << "Vase rozmistene lode" << endl;
        showYourMAp();
        cout << "Zadejte pozici lode (0-4)[x y]: ";
        cin >> x >> y;
        if(matrixPlayer[x][y] != 1){
            matrixPlayer[x][y] = 1;
            ships++;
        }
    }
}


bool attack(int x, int y){
    matrixMap[x][y] = 2;
    if(matrixComputer[x][y] == 1){
        numberOfCOmputerShips--;
        matrixComputer[x][y] = 0;
        matrixMap[x][y] = 3;
        return true;
    }
    return false;
}

bool attackPlayer(){
    int x = rand() % rows;
    int y = rand() % columns;
    if(matrixPlayer[x][y] == 1){
        cout << "Vase lod byla zasazena" << endl;
        numberOfPlayersShips--;
        return true;
    } else if(matrixPlayer[x][y] == 2){
        attackPlayer();
    }
    matrixPlayer[x][y] = 2;
    return false;
}


int main() {

    int pos1, pos2;
    bool gameOver = false;

    srand(time(NULL));

    clear();
    setComputerShips();
    setPlayerShip();


    while (!gameOver){
        system("clear");

        cout << "Zbyva \033[31m" << numberOfCOmputerShips << "\033[0m souperovych lodi" << endl;
        cout << "Zbyva \033[32m" << numberOfPlayersShips << "\033[0m vasich lodi" << endl;
        showBattlePlan();

        cout << "Zadejte strelnou pozici (0-4)[x y]: ";
        cin >> pos1 >> pos2;

        if(attack(pos1, pos2)){
            cout << "\033[32mZasah!\033[0m strilite znovu..." << endl;
            continue;
        } else {
            cout << "Vedle..." << endl;
        }

        attackPlayer();

        if(numberOfCOmputerShips == 0){
            system("clear");
            cout << "\033[32mVitezstvi\033[0m" << endl;
            gameOver = true;
        } else if(numberOfPlayersShips == 0){
            system("clear");
            cout << "\033[31mPorazka\033[0m" << endl;
            gameOver = true;
        }
    }

    return 0;
}
