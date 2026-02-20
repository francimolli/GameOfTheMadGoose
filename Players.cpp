//
//  main.cpp
//  GiocoDellOcaPazza
//
//  Created by Francesco Mollica 'alone in the light'
//  Copyright © 2018. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <time.h>
#include "Tabellone.hpp"
#include "Players.hpp"
#include "Boxes.hpp"



using namespace std;
using namespace box;

Players *giocat::CreatePlayers(string nam, string symb, int i, Players *pros, Players *prim){
    Players *RS = new Players;
    RS->Name = nam;
    RS->Symbol = symb;
    RS->GameOrder = i;
    RS->BillboardPOS = 1;
    RS->Cage = 0;
    RS->next = pros;
    RS->prev = prim;
    return RS;
}


Players *giocat::SetName(int number, Players *pls){
    string nomePLAYER;
    string symb;
    bool symbScelt = false;
    bool scelti[10];
    for( int d = 1; d < 9; d++){
        scelti[d] = false;
    };
    Players* ret = pls;
    Players* temp = ret;
    Players* file = ret;
    for(int i = 1; i < (number + 1); i++){
        cout << "What's your name, player number " << i << "?" << "\n ";
        if(true){
            cin >> nomePLAYER;
            //da sistem
            if(i != 1){

                for(int k = 0; k < i; k++){
                    if(ret->Name == nomePLAYER){
                        cout<< "Already used this name in our DataBase. Retry.";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << " \n What's your name, player number " << i << "?" << "\n ";
                        cin >> nomePLAYER;
                        cout << "\n";
                        k=0;
                        ret = pls;
                    }

                    ret= ret->next;
                };
                }
            }
        cout<< "Choose a symbol : enter the number near the symbol \n 1) ¥ \t 4) ≠ \t 7) π \n 2) √ \t 5) Ω \t 8) ∑ \n 3) ∂ \t 6) ∆ \t 9) ∫ \n \n";
        int numSymb;
        cout << "What symbol do you want " << nomePLAYER << "?" << "\n ";
        cin >> numSymb;
        while(numSymb < 1 || numSymb > 9){
            if (!cin.good()){
                cout << "Insert a number! ";
                cout << ". \t \n . \t \n. \t \n . \t \n";
                stop();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');}
            else if(numSymb < 1 || numSymb > 9){
                cout<< "Invalid number choosed for the symbol";
                cout << ". \t \n . \t \n. \t \n . \t \n";
                stop();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin >> numSymb;
            cout << "\n";
        }

        while(!symbScelt){
                if( scelti[1] == false && numSymb == 1){
                    symb = "¥";
                    symbScelt = true;
                    scelti[1] = true;
                }
                else if( scelti[2] == false && numSymb == 2){
                    symb = "√";
                    symbScelt = true;
                    scelti[2] = true;
                }
                else if( scelti[3] == false && numSymb == 3){
                    symb = "∂";
                    symbScelt = true;
                    scelti[3] = true;
                }
                else if( scelti[4] == false && numSymb == 4){
                    symb = "≠";
                    symbScelt = true;
                    scelti[4] = true;
                }
                else if( scelti[5] == false && numSymb == 5){
                    symb = "Ω";
                    symbScelt = true;
                    scelti[5] = true;
                }
                else if( scelti[6] == false && numSymb == 6){
                    symb = "∆";
                    symbScelt = true;
                    scelti[6] = true;
                }
                else if( scelti[7] == false && numSymb == 7){
                    symb = "π";
                    symbScelt = true;
                    scelti[7] = true;
                }
                else if( scelti[8] == false && numSymb == 8){
                    symb = "∑";
                    symbScelt = true;
                    scelti[8] = true;
                }
                else if( scelti[9] == false && numSymb == 9){
                    symb = "∫";
                    symbScelt = true;
                    scelti[9] = true;
                }
            if(symbScelt == false){
                cout<< "This symbol has already been choosed";
                cout << ". \t \n . \t \n. \t \n . \t \n";
                cout << "Choose a different symbol";
                cout << ". \t \n . \t \n. \t \n . \t \n";
                stop();
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> numSymb;
            }
        }
        symbScelt=false;
        if (i == 1){
            temp = CreatePlayers(nomePLAYER, symb, i, temp , pls);
            file = temp;
            temp->next = temp;
            ret = CreatePlayers(nomePLAYER, symb, i, temp , pls);
        } else if(i==2){
            temp = CreatePlayers(nomePLAYER, symb, i, ret, file);
            ret = temp;
            temp->next = file;
        } else if (i == (number)){
            temp = CreatePlayers(nomePLAYER, symb, i, file, pls);
            temp->next->prev = pls->next;
        } else {
            temp = CreatePlayers(nomePLAYER, symb, i, ret, pls);
        }

        pls = temp;
        if(i>1){
            pls->prev->next =pls;}
        temp= temp->next;
        cout << "\n";
    }
    temp->prev = pls;
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-GOP-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- \n\n";
    cout << "\n";
    cout << number << " Gamers!";
    cout << ". \t \n . \t \n. \t \n . \t \n";
    cout << "Ready to GOP?" <<endl;
    stop();
    stop();
    return pls;
    }
Players *giocat::OrdinaPlayers(Players *pls, int number){
    Players *t = NULL;
    Players *temp = NULL;
    int exe = 1;
    int tmp;
    int i = 0;
    int j = 0;
    string n;
    while(exe == 1) {
        exe = 0;
        for(t = pls; i < number; t = t->next) {
            j = 0;
            for(temp = t->next; j < number; temp = temp->next) {
                if(t->BillboardPOS > temp->BillboardPOS) {
                    tmp = t->BillboardPOS;
                    t->BillboardPOS = temp->BillboardPOS;
                    temp->BillboardPOS = tmp;
                    tmp = t->Cage;
                    t->Cage = temp->Cage;
                    temp->Cage = tmp;
                    tmp = t->GameOrder;
                    t->GameOrder = temp->GameOrder;
                    temp->GameOrder = tmp;
                    n = t->Name;
                    t->Name = temp->Name;
                    temp->Name = n;
                    n = t->Symbol;
                    t->Symbol = temp->Symbol;
                    temp->Symbol = n;
                    exe = 1;
                    
                }
                j++;
            }
            i++;
        }
    }
    return t;
};
Players *giocat::RiOrdinaPlayers(Players *pls, int number){
    Players *t = NULL;
    Players *temp = NULL;
    int exe = 1;
    int tmp;
    int i = 0;
    int j = 0;
    string n;
    while(exe == 1) {
        exe = 0;
        for(t = pls; i < number; t = t->next) {
            j = 0;
            for(temp = t->next; j < number; temp = temp->next) {
                if(t->GameOrder < temp->GameOrder) {
                    tmp = t->BillboardPOS;
                    t->BillboardPOS = temp->BillboardPOS;
                    temp->BillboardPOS = tmp;
                    tmp = t->Cage;
                    t->Cage = temp->Cage;
                    temp->Cage = tmp;
                    tmp = t->GameOrder;
                    t->GameOrder = temp->GameOrder;
                    temp->GameOrder = tmp;
                    n = t->Name;
                    t->Name = temp->Name;
                    temp->Name = n;
                    n = t->Symbol;
                    t->Symbol = temp->Symbol;
                    temp->Symbol = n;
                    exe = 1;
                    
                }
                j++;
            }
            i++;
        }
    }
    return t;
}
