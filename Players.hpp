//
//  main.cpp
//  GiocoDellOcaPazza
//
//  Created by Francesco Mollica 'alone in the light'
//  Copyright © 2018. All rights reserved.
//

#ifndef Players_hpp
#define Players_hpp

#include <stdio.h>
#include <string.h>

using namespace std;

struct Players{
    string Name;
    string Symbol;
    int GameOrder;
    int BillboardPOS;
    int Cage;
    Players *prev;
    Players *next;
};
namespace giocat{
    Players *CreatePlayers(string nam, string symb, int i, Players *pros, Players *prim);
    Players *SetName(int number, Players *pls);
    Players *SetSymbol(int Nsymb[], string name);
    Players *OrdinaPlayers(Players *turn, int number);
    Players *RiOrdinaPlayers(Players *turn, int number);
};


#endif /* Players_hpp */
