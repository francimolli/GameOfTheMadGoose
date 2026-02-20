//
//  main.cpp
//  GiocoDellOcaPazza
//
//  Created by Francesco Mollica 'alone in the light'
//  Copyright © 2018. All rights reserved.
//
#include <iostream>
#include <stdlib.h>
#include "Cards.hpp"
#include <ctime>
#include <string.h>
#include "Players.hpp"
#include "Cards.hpp"
#include "Tabellone.hpp"
#include "Boxes.hpp"

using namespace std;
using namespace giocat;
using namespace card;
using namespace tabel;
using namespace box;

int card::NumeroCarte(){
    srand((unsigned int)time(NULL));
    int randomatic = (( rand()%120)+1);
    if (randomatic< 40 ){
        randomatic = randomatic +40;
    }else{
        
        return randomatic;
    }
    return randomatic;
}
mazzo card::InizializzaMazzo(mazzo maz){
    int numCarte = NumeroCarte();
    srand((unsigned int)time(NULL));
    for(int i = 1; i < numCarte; i++){
        int virtualroll = (( rand()%6)+1);
        maz.tipocarta[i] = virtualroll;
    };
    return (maz);
}

Players *card::executeCard(Players *turn, int carta, int caselle, int number){
    mazzo maz;
    maz = InizializzaMazzo(maz);
    if(maz.tipocarta[carta] == 1){
        cout << "Roll the dice again....but....you can go up or down now...";
        srand((unsigned int)time(NULL));
        int virtualroll = (( rand() % 11) + 2);
        cout << "Number ..." << virtualroll;
        stop();
        int cheers = (( rand() % 2) + 1);
        if (cheers == 1){
            turn->BillboardPOS = turn->BillboardPOS + virtualroll;
            cout<< " UP!";
        } else if (cheers == 2 ){
            turn->BillboardPOS = turn->BillboardPOS - virtualroll;
            cout<< " DOWN!";
            if(turn->BillboardPOS < 0){
                turn->BillboardPOS = 0;
            }
        }
        cout << ". \t \n . \t \n. \t \n . \t \n";
        stop();
        cout << "Your box is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
        stop();
        stop();
        cout << ". \t \n . \t \n. \t \n . \t \n";
    }else if(maz.tipocarta[carta] == 2){
        cout << "For 1 turn now, you will stay in the....GOOSE CAGE....";
        stop();
        stop();
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn->Cage = 2;
    }else if(maz.tipocarta[carta] == 3){
        cout << "This card have no effect...";
        stop();
        cout << ". \t \n . \t \n. \t \n . \t \n";
    }else if(maz.tipocarta[carta] == 4){
        stop();
        cout << "Just take a new card...";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn = executeCard(turn, carta, caselle, number);
    }else if(maz.tipocarta[carta] == 5){
        stop();
        cout << "Go one box on...";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn->BillboardPOS = turn->BillboardPOS + 1;
    }else if(maz.tipocarta[carta] == 6){
        stop();
        cout << "Go one box back...";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn->BillboardPOS = turn->BillboardPOS - 1;
    }
    return turn;
}
