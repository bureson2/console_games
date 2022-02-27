#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cstring>
#include "Menu.h"

using namespace std;


int main(int argc, char** argv) {

    if(argc == 2 && strcmp(argv[1], "--help")==0)
    {
        cout << "Program nabizi pohyb po male herni mapce\n";
        cout << "Hrac je symbolizovan cernym obdelnikem s bilym symbolem\n";
        cout << "Tento symbol je mozne zmenit pruchodem skrz cerveny obedlnik\n";
        cout << "Pohyb po mapce je mozny pomoci klaves: w, a, s, d (bez CapsLk)\n";
        cout << "Hru je mozne ukoncit stiknutim q\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Na mapce se nachazi 5 modrych obedlniku oznacene: A, B, C, D, E\n";
        cout << "Pruchod modrym obdelnikem spusti vybranou hru\n";
        cout << "Pod pismenem A je schovana hra Cross the road\n";
        cout << "Pod pismenem B je schovana Pong (ovladani: w/s a i/k)\n";
        cout << "Pod pismenem C je schovana hra Ships (ovladani zadavani cisel 0-4)\n";
        cout << "Pod pismenem D je schovana hra Snake (ovladani: w, a, s, d)\n";
        cout << "Pod pismenem E je schovana hra Flappy birds (vzlet: w)\n";
        cout << "Vsechny hry je mozne ukoncit pomoci pismena x\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Zakladni herni logika her nekterych her vychazi z programatorskych tutorialu ke konzolovym hram\n";
        cout << "Temto hram byla upravena herni logika (napr. v pripade lodi jednoducha logika pro hru proti pocitaci)\n";
        cout << "Pripadne byly cele predelany do objektove podoby, s vyjimkou jiz zminenych lodi\n";
        cout << "U her Snake, Flappy Birds a Pong dochazi k postupnemu zrychlovani hry";
        cout << "Graficke hratky s konzoli, ci zprovozneni Windows knihovny Conio.h pro Linux uz nasledne vychazi z experimentovani\n";
        cout << "Z duvodu spatneho zpracovani predelane knihovny Conio.h neni mozne mit obsazene vsechny hry v samotnenem souboru (ani za pomoci PRAGMA, atd.)\n";
        cout << "Proto jsou ostatni hry prilozeny samostatne a hlavni program vola jen spustitelne soubory";

        return 0;
    }

    Menu menu = Menu();

    while(!menu.gameOver){
        menu.draw();
        menu.input();
        menu.logic();
        this_thread::sleep_for(chrono::milliseconds(250));
    }

    return 0;
}
