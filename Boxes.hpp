//
//  main.cpp
//  GiocoDellOcaPazza
//
//  Created by Francesco Mollica 'alone in the light'
//  Copyright © 2018. All rights reserved.
//

#ifndef Boxes_hpp
#define Boxes_hpp

#include <stdio.h>
#include "Players.hpp"
#include "Tabellone.hpp"

namespace box{
    Players *CageBoxe(Players *turn);
    void Plus3(Players *turn);
    void Minus3(Players *turn);
    void TestaCroce(Players *turn, int caselle);
    void MoveToNext(Players *turn, int number);
    void MoveToPrevious(Players *turn, int number);
    void TestaCroce15(Players *turn, int caselle);
    Players *Elimina(Players *turn);
    int stop();
};
#endif /* Boxes_hpp */
