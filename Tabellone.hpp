//
//  main.cpp
//  GiocoDellOcaPazza
//
//  Created by Francesco Mollica 'alone in the light'
//  Copyright © 2018. All rights reserved.
//

#ifndef Tabellone_hpp
#define Tabellone_hpp

#include <stdio.h>
#include <stdlib.h>

#include "Players.hpp"
#include "Cards.hpp"

#define MAX 160

struct tabellone{
    int tipocasella[MAX];
};

namespace tabel{
    int CaselleTabellone();
    void printTab(Players *turn, int number, int caselle);
    tabellone InizializzaTabellone(int caselle, tabellone tab);
    Players *execute(Players *turn, int number, int caselle, tabellone tab);
    void PrintBillboard(Players *turn, tabellone tab, int number, int caselle, int numRound);
};

#endif /* Tabellone_hpp */
