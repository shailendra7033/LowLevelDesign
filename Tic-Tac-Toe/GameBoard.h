#pragma once
#include"Player.h"
#include<bits/stdc++.h>
using namespace std;

#define SIZE_GAME_BOARD 3
#define NUM_OF_PLAYERS 2




class GameBoard{

    int gameBoard[SIZE_GAME_BOARD][SIZE_GAME_BOARD];
    vector<Player> players;
    int currPlayer;

public:
    int calculateWinner(int row, int col);
    bool playTurn(int row, int col);
    void printBoard();



    //getter setter
    int getCurrPlayer() { return currPlayer; }
    void setCurrPlayer(int cplyr) { currPlayer=cplyr; }


   // Constructor
    GameBoard(){

        for(int i=0;i<SIZE_GAME_BOARD;i++){

            for(int j=0;j<SIZE_GAME_BOARD;j++){
                gameBoard[i][j]=-1;
            }
        }

        Player play1 = Player();
        Player play2 =  Player();
        this->players.push_back(play1);
        players.push_back(play2);

        play1.setPlaySymbol(symbol::ZERO);  // 1 refer to ZERO
        play2.setPlaySymbol(symbol::CROSS); // 2 refer to CROSS


    }

    
};