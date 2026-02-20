//
//  main.cpp
//  GiocoDellOcaPazza
//
//  Created by Francesco Mollica 'alone in the light'
//  Copyright © 2018. All rights reserved.
//

#ifndef Cards_hpp
#define Cards_hpp

#include <stdio.h>
#include "Players.hpp"
#include "Tabellone.hpp"

#define MAX 160

struct mazzo{
    int tipocarta[MAX];
};

namespace card{
    int InizializzaMazzo();
    int NumeroCarte();
    mazzo InizializzaMazzo(mazzo maz);
    Players *executeCard(Players *turn, int carta, int caselle, int number);
};
#endif /* Cards_hpp */
