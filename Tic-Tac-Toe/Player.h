#pragma once
#include<stdio.h>
#include"GameBoard.h"

// symbol should be enum type of 0 and x
// #define char playZero '0';
// #define char playCross 'x';
enum symbol{
    ZERO = 0,
    CROSS = 1,
    DRAW =2,
    PLAY =3
};

class Player{

    symbol playSymbol;
    // // bool isTurn;
    

    
    // // void setIsTurn(bool flag) isTurn=flag;
    // // bool getIsTurn() return isTurn;
public:
    void setPlaySymbol(symbol playSym) { playSymbol=playSym; }
    symbol getPlaySymbol() { return playSymbol; }
    
};