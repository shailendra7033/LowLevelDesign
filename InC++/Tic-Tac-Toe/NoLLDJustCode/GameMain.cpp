#pragma once
#include"GameBoard.h"
#include<bits/stdc++.h>
using namespace std;




int main(){



    cout<<"WELCOME TO TIC TAC TOE";
    cout<<"\n NO CHOICE WILL BE GIVEN, Will start the game direct with TURN of ZERO";
    cout<<"\n ENTER 0 for player ZERO and 1 for CROSS player";
    cout<<"\n Will print the board after every turn";



    cout<<"\n \n LET's Start";
    GameBoard *gamebrd = new GameBoard();
    gamebrd->setCurrPlayer(0);
    while(gamebrd->calculateWinner(0,0) == symbol::PLAY){
        int r, c;
        cout<<"Enter Row no ";
        cin>>r;
        cout<<"Enter Col no ";
        cin>>c;
        if(!gamebrd->playTurn(r, c)){
            cout<<"Invalid move, try again.";
            continue;
        }
        int res=gamebrd->calculateWinner(r, c);

        if(res == symbol::DRAW){
            cout<<"GAME OVER DRAW";
            return 0;
        }else if(res == symbol::ZERO){
            cout<<"Wohoo ZERO WON";
            return 0;
        }else if(res == symbol::CROSS){
            cout<<"CROSS WON";
            return 0;
        }

        gamebrd->printBoard();


    }

    
}