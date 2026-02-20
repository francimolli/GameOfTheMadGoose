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
#include "Tabellone.hpp"
#include "Boxes.hpp"
#include "Cards.hpp"

using namespace std;
using namespace box;
using namespace card;

int tabel::CaselleTabellone(){
    srand((unsigned int)time(NULL));
    int randomatic = (( rand()%120)+1);
    if (randomatic< 40 ){
        randomatic = randomatic +40;
    } else {
        
        return randomatic;
    }
    return randomatic;
}

tabellone tabel::InizializzaTabellone(int caselle, tabellone tab){
    tab.tipocasella[1] = 9;
    srand((unsigned int)time(NULL));
    for(int i = 2; i < caselle; i++){
//i%3 == 0) ||
        if( i%4 == 0){
            tab.tipocasella[i] = 9;
        }else{
            int virtualroll = (( rand()%10));
            tab.tipocasella[i] = virtualroll;
        }
    };
    return (tab);
}

Players *tabel::execute(Players *turn, int number, int caselle, tabellone tab){
    Players * pls = turn;
    for ( int f = 0; f < number ; f++){
        if(turn->BillboardPOS == caselle){
            return turn;
        }else if(turn->BillboardPOS > caselle) {
            cout << ". \t \n . \t \n. \t \n . \t \n";
            cout << "Ooh, you went too far! Boxes are only " << caselle << " you arrived till " << turn->BillboardPOS << ", turn back for " << (turn->BillboardPOS-caselle) << " from " << caselle;
            turn->BillboardPOS = caselle - (turn->BillboardPOS - caselle);
            stop();
            cout << ". \t \n . \t \n. \t \n . \t \n";
            cout << "Your box is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
            cout << ". \t \n . \t \n. \t \n . \t \n";
        }
        turn = turn->next;
    };
    if(tab.tipocasella[turn->BillboardPOS] == 0){
        Plus3(turn);
        if(tab.tipocasella[turn->BillboardPOS] == 1){
        }else{
            turn = execute(turn, number, caselle, tab);
        }
        stop();
        stop();
        
    }else if(tab.tipocasella[turn->BillboardPOS] == 1){
        Minus3(turn);
        if(tab.tipocasella[turn->BillboardPOS] == 0){
        }else{
            turn = execute(turn, number, caselle, tab);        }
        stop();
        stop();
        
    }else if(tab.tipocasella[turn->BillboardPOS] == 2){
        TestaCroce(turn, caselle);
        pls = turn;
            turn = execute(turn, number, caselle, tab);
        stop();
        stop();
        
    }else if(tab.tipocasella[turn->BillboardPOS] == 3){
        int gameord = turn->GameOrder;
        MoveToNext(turn, number);
        stop();
        while(turn->GameOrder != gameord){
            turn = turn->next;
        }
        if(tab.tipocasella[turn->BillboardPOS] == 4 || tab.tipocasella[turn->BillboardPOS] == 3){
        }else{
            turn = execute(turn, number, caselle, tab);
        }
        stop();
        
    }else if(tab.tipocasella[turn->BillboardPOS] == 4){
        int gameord = turn->GameOrder;
        MoveToPrevious(turn, number);
        stop();
        while(turn->GameOrder != gameord){
            turn = turn->next;
        }
        if(tab.tipocasella[turn->BillboardPOS] == 3 || tab.tipocasella[turn->BillboardPOS] == 4){
        }else{
            turn = execute(turn, number, caselle, tab);        }
        stop();
    }else if(tab.tipocasella[turn->BillboardPOS] == 5){
        TestaCroce15(turn, caselle);
        pls = turn;
            turn = execute(turn, number, caselle, tab);
        stop();
        stop();
        
    }else if(tab.tipocasella[turn->BillboardPOS] == 6){
        cout << "Take a card!!";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        srand((unsigned int)time(NULL));
        int expos = turn->BillboardPOS;
        int ncard = NumeroCarte();
        int carta = (( rand()%ncard));
        turn = executeCard(turn, carta, caselle, number);
        if(expos != turn->BillboardPOS){
            turn = execute(turn, number, caselle, tab);}
        }else if(tab.tipocasella[turn->BillboardPOS] == 7){
        cout << "Roll the dice again....";
        srand((unsigned int)time(NULL));
        int virtualroll = (( rand() % 11) + 2);
        turn->BillboardPOS = turn->BillboardPOS + virtualroll;
        cout << "Number ..." << virtualroll;
        cout << ". \t \n . \t \n. \t \n . \t \n";
        stop();
        cout << "Your boxe is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
        cout << ". \t \n . \t \n. \t \n . \t \n";
        stop();
        stop();
        turn = execute(turn, number, caselle, tab);
        cout << ". \t \n . \t \n. \t \n . \t \n";
        
    }else if(tab.tipocasella[turn->BillboardPOS] == 8){
        cout << "GOOSE CAGE!";
        stop();
        stop();
        cout << ". \t \n . \t \n. \t \n . \t \n";
        turn->Cage = 3;
        
    }else if(tab.tipocasella[turn->BillboardPOS] == 9){
        //empty cage
    }
    return turn;
    }

void tabel::PrintBillboard(Players *pls, tabellone tab, int number, int caselle, int numRound){
    cout << "Now we are, at the end of the round n°" << numRound << " \nAs we can see, the following ranking will show you better the situation....\n\n";
    Players *t = NULL;
    t = giocat::OrdinaPlayers(pls, number);
    for (int i = 0; i < number; i++){
        if(t->Cage != 0){
                    cout << "Ranking: " << (i + 1) << "   Player: " << t->Name << " - " << t->Symbol <<   "   Position: " << t->BillboardPOS << "   CAGE" << endl;
        }else{
            cout << "Ranking: " << (i + 1) << "   Player: " << t->Name << " - " << t->Symbol <<    "   Position: " << t->BillboardPOS << endl;}
        t = t -> next;
    };
    printTab(t, number, caselle);
    t = giocat::RiOrdinaPlayers(pls, number);
    stop();
};

void tabel::printTab(Players *g, int num, int cas){
    cout << endl;
    cout << "START";
    for (int i=0; i < cas; i++){
        // imposto righe da 10 caselle
        if ((i % 10==0) && i != 0){
            cout << "\n \t";
        };
        cout << "[";
        for (int j = 0 ; j < num; j++){
            if (g->BillboardPOS == (i+1))cout << g->Symbol;
            else cout << " ";
            g = g->next;
        }
        cout << "]";
    }
    cout << "END" << endl;
}
