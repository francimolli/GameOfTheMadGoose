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
#include "Players.hpp"
#include "Boxes.hpp"
#include "Cards.hpp"

using namespace std;
using namespace giocat;
using namespace tabel;
using namespace box;
using namespace card;

int SelectionPlayers(int numGioc){
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-GOP-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.- \n\n" << endl;
    cout << "How many players do you are? max 9!" << "\n ";
    cin >> numGioc;
    while(numGioc < 2 || numGioc > 9){
        if (!cin.good()){
            cout << "Insert a number! ";
            cout << ". \t \n . \t \n. \t \n . \t \n";
            stop();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');}
        else if(numGioc < 2 || numGioc > 9){
            cout<< "Invalid number player";
            cout << ". \t \n . \t \n. \t \n . \t \n";
            stop();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin >> numGioc;
        cout << "\n";
        }
    return numGioc;
}

int Rolla(){
    getchar();
    srand((unsigned int)time(NULL));
    int virtualroll = (( rand() % 11) + 2);
    return virtualroll;
}

Players *Game(int number, Players *pls, int caselle, tabellone tab){
    bool end = false;
    int numRound = 0;

    Players* turn = pls;
    while (end == false){
        numRound = numRound + 1;
        
        for (int i = 0; i < number; i++){
            
            CageBoxe(turn);

            if(turn->Cage == 0){
                cout << "∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ Go on player, " << turn->Name << " " << turn->Symbol << " ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞ ∞";
                cout << ". \t \n . \t \n. \t \n . \t \n";
                stop();
                stop();
                cout<<"Press ENTER to roll the dices"<<endl;
                getchar();

                int virtualroll = Rolla();
                cout << "Number ..." << virtualroll;
                stop();
                cout << ". \t \n . \t \n. \t \n . \t \n";
                (turn->BillboardPOS = turn->BillboardPOS + virtualroll);
                //cout << "Your box is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
                if(turn->BillboardPOS == caselle){
                    cout << "Your box is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
                    cout << "Player " << turn->Name << " WON!!!";
                    i = number;
                    end = true;
                }else if( turn->BillboardPOS > caselle){
                    cout << ". \t \n . \t \n. \t \n . \t \n";
                    cout << "Ooh, you went too far! Boxes are only " << caselle << " you arrived till " << turn->BillboardPOS << ", turn back for " << (turn->BillboardPOS-caselle) << " from " << caselle;
                    turn->BillboardPOS = caselle - (turn->BillboardPOS - caselle);
                    stop();
                    cout << ". \t \n . \t \n. \t \n . \t \n";
                    cout << "Your box is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
                    turn = execute(turn, number, caselle, tab);
                }else{
                    cout << "Your box is the number = " << turn->BillboardPOS << ", of " << caselle << " boxes.";
                    stop();
                    cout << ". \t \n . \t \n. \t \n . \t \n";
                    turn = execute(turn, number, caselle, tab);
                }
                for ( int f = 0; f < number ; f++){
                    if(turn->BillboardPOS == caselle){
                        cout << ". \t \n . \t \n. \t \n . \t \n";
                        cout << turn->Symbol << " " << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << "CONGRATULATIONS " << turn->Name << ", YOU WON!" << turn->Symbol << " " << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " "  << turn->Symbol << " " ;
                        end = true;
                        i = number;
                    }
                    turn = turn->next;
                };
            }
                turn = turn->next;
        };
        if(!end){
            Players *pls = turn;
            PrintBillboard(pls, tab, number, caselle, numRound);
            stop();
            cout << ". \t \n . \t \n. \t \n . \t \n";
        }
    };
    return turn;
}

int main() {
    srand((unsigned int)time(NULL));
    int numGioc = 0;
    numGioc = SelectionPlayers(numGioc);
    Players* pls = NULL;
    tabellone tab;
    //creazione del numero di giocatori scelti
    pls = SetName(numGioc, pls);
    cout << ". \t \n . \t \n. \t \n . \t \n";
    int numCaselle = CaselleTabellone();
    cout << "The Billboard is composed of: " << numCaselle << " BOXES";
    //funzione di inizializzazione del numero di caselle
    tab = InizializzaTabellone(numCaselle, tab);
    cout << ". \t \n . \t \n. \t \n . \t \n";
    //elimina( pls);
    pls= pls -> next;
    pls = Game(numGioc, pls, numCaselle, tab);
    return 0;
}
