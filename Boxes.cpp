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
#include "Boxes.hpp"
#include "Tabellone.hpp"

int box::stop(){
    int x, p;
    
    for (x = 1; x <= 32767; x++)
        for (p = 1; p <= 32767; p++)
        {}
    
    return 0;
};

Players *box::CageBoxe(Players *turn){
    if(turn->Cage == 3){
        cout << turn->Name << ", you got 2 turn more... IN DA CAGE!";
        stop();
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn->Cage = 2;
    }else if(turn->Cage == 2){
        cout << turn->Name << ", you got 1 turn more... IN DA CAGE!";
        stop();
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn->Cage = 1;
    }else if(turn->Cage == 1){
        cout << turn->Name << ", now you are free from the cage!!";
        stop();
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn->Cage = 0;
    }
    return turn;
}

void box::Plus3(Players *turn){
    turn->BillboardPOS = (turn->BillboardPOS + 3);
    cout << "You get 3 positions on, new pos: = "  << turn->BillboardPOS;
    cout << ". \t \n . \t \n. \t \n . \t \n";
}

void box::Minus3(Players *turn){
    turn->BillboardPOS = (turn->BillboardPOS - 3);
    if (turn->BillboardPOS < 0){
        turn->BillboardPOS = 0;
    }
    cout << "You went back of 3 positions, new pos: = " << turn->BillboardPOS;
    cout << ". \t \n . \t \n. \t \n . \t \n";
}

void box::TestaCroce(Players *turn, int caselle){
    cout << "+ or - 25 % \n Try your lucky? choose TESTA or CROCE (T/C)";
    cout << ". \t \n . \t \n. \t \n . \t \n";
    string lucky = "";
    while (lucky == ""){
        cin >> lucky;}
    int virtualroll = (( rand() % 2) + 1);
    while (lucky != "c" && lucky != "C" && lucky != "t" && lucky != "T"){
        cout<< "Enter a valid value(t/c)"<< endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>lucky;
    }
    if(((lucky == "c" || lucky == "C") && virtualroll== 1) || ((lucky == "t" || lucky == "T") && virtualroll== 2)){
        cout << "YOU WON!!";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        if(turn->BillboardPOS < 4){
            turn->BillboardPOS = turn->BillboardPOS +1;
        }else {
            turn->BillboardPOS = turn->BillboardPOS + int((turn->BillboardPOS*25) /100);
        }
        cout << "Your boxe is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
        cout << ". \t \n . \t \n. \t \n . \t \n";
    }else{
        cout << "YOU LOST, next time you will try again!";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        if(turn->BillboardPOS < 4){
            turn->BillboardPOS = turn->BillboardPOS - 1;
        }else {
            turn->BillboardPOS = turn->BillboardPOS - int((turn->BillboardPOS*25) /100);
        }
        if(turn->BillboardPOS < 0){
            turn->BillboardPOS = 0;
        }
        cout << "Your boxe is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
        cout << ". \t \n . \t \n. \t \n . \t \n";
    }
}

void box::MoveToNext(Players *turn, int number){
    Players* tmp = NULL;
    Players* pls = turn;
    bool esatto = true;
    string name;
    name = pls->Name;
    tmp = giocat::OrdinaPlayers(pls, number);
    cout << "You are having a jump!!!! Moving to the next position.";
    stop();
    while(esatto){
        if(tmp->Name == name){
            if( tmp->BillboardPOS < tmp->prev->BillboardPOS){
                tmp->BillboardPOS = tmp->prev->BillboardPOS;
                cout << ". \t \n . \t \n. \t \n . \t \n";
                cout << "New position: " << tmp->BillboardPOS;
                cout << ". \t \n . \t \n. \t \n . \t \n";
                esatto = false;
            } else{
                cout << ". \t \n . \t \n. \t \n . \t \n";
                cout << "You already are the first in the billboard's positions.... HOLD ON!!!";
                cout << ". \t \n . \t \n. \t \n . \t \n";
                esatto = false;
            }
        }
        tmp = tmp -> next;
    }

    turn = giocat::RiOrdinaPlayers(pls, number);
}
void box::MoveToPrevious(Players *turn, int number){
    Players* tmp = NULL;
    Players* pls = turn;
    bool esatto = true;
    string name;
    name = pls->Name;
    tmp = giocat::OrdinaPlayers(pls, number);
    cout << "Debacle! You are moving back to the previous position.";
    stop();
    while(esatto){
        if(tmp->Name == name){
            if(tmp->BillboardPOS > tmp->next->BillboardPOS){
                tmp->BillboardPOS = tmp->next->BillboardPOS;
                cout << ". \t \n . \t \n. \t \n . \t \n";
                cout << "New position: " << tmp->BillboardPOS;;
                cout << ". \t \n . \t \n. \t \n . \t \n";
                esatto = false;
            }else{
                cout << ". \t \n . \t \n. \t \n . \t \n";
                cout << "You already are in the last billboard's position.... COME ON!!!";
                cout << ". \t \n . \t \n. \t \n . \t \n";
                esatto = false;
            }
        }
        tmp = tmp -> next;
    }
    turn = giocat::RiOrdinaPlayers(pls, number);
}

void box::TestaCroce15(Players *turn, int caselle){
    cout << "+ or - 10 % \n Try your lucky? choose TESTA or CROCE (T/C)";
    cout << ". \t \n . \t \n. \t \n . \t \n";
    string lucky = "";
    while (lucky == ""){
        cin >> lucky;}
    int virtualroll = (( rand() % 2) + 1);
    while (lucky != "c" && lucky != "C" && lucky != "t" && lucky != "T"){
        cout<< "Enter a valid value(t/c)"<< endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>>lucky;
    }
    if(((lucky == "c" || lucky == "C") && virtualroll== 1) || ((lucky == "t" || lucky == "T") && virtualroll== 2)){
        cout << "YOU WON!!";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        if(turn->BillboardPOS < 10){
            turn->BillboardPOS = turn->BillboardPOS + 1;
        }else {
            turn->BillboardPOS = turn->BillboardPOS + int((turn->BillboardPOS*10) /100);
        }
        cout << "Your boxe is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
        cout << ". \t \n . \t \n. \t \n . \t \n";
    }else{
        cout << "YOU LOST, next time you will try again!";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        if(turn->BillboardPOS < 10){
            turn->BillboardPOS = turn->BillboardPOS - 1;
        }else {
            turn->BillboardPOS = turn->BillboardPOS - int((turn->BillboardPOS*10) /100);
        }
        if(turn->BillboardPOS < 0){
            turn->BillboardPOS = 0;
        }
        cout << "Your boxe is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
        cout << ". \t \n . \t \n. \t \n . \t \n";
    }
}

