#pragma once
#include"GameBoard.h"
using namespace std;
bool GameBoard::playTurn(int row, int col){
         
    if(gameBoard[row][col]!=-1){
        cout<<"Invalid space, use free space of board";
        return false;
    }else{
        
        gameBoard[row][col] = currPlayer;

        if(currPlayer == symbol::ZERO)
        {
            currPlayer= symbol::CROSS;
        }else
        {
            currPlayer= symbol::ZERO ;
        }
    }

    return true;

}


/*
To caluclate need to call after every turn of play
*/
int GameBoard::calculateWinner(int row, int col){


    // looking rowise + columnwise
   

        int cross_count_row=0, zero_count_row=0;
        int cross_count_col=0, zero_count_col=0;
        int cross_count_dia=0, zero_count_dia=0;
        int cross_count_dia2=0, zero_count_dia2=0;

        // looking row and cloumnise
        for(int j=0;j<SIZE_GAME_BOARD;j++){
            if(gameBoard[row][j]==symbol::ZERO ){
                zero_count_row++;
            }else if(gameBoard[row][j]==symbol::CROSS){
                cross_count_row++;
            }

            if(gameBoard[j][col]==symbol::ZERO ){
                zero_count_col++;
            }else if(gameBoard[j][col]==symbol::CROSS){
                cross_count_col++;
            }
        }



        // looking diagonal wise (0,0), (1,1), (2,2)

        for(int i=0,j=0; i<SIZE_GAME_BOARD && j<SIZE_GAME_BOARD;i++,j++){
            if(gameBoard[j][i]==symbol::ZERO ){
                zero_count_dia++;
            }else if(gameBoard[j][i]==symbol::CROSS){
                cross_count_dia++;
            }
        }

        // looking digaonal wise (0,2), (1,1), (2,0)
        for(int i=0,j=SIZE_GAME_BOARD-1; i<SIZE_GAME_BOARD && j>=0;i++,j--){
            if(gameBoard[i][j]==symbol::ZERO ){
                zero_count_dia2++;
            }else if(gameBoard[i][j]==symbol::CROSS){
                cross_count_dia2++;
            }
        }


        if(zero_count_row==3 || zero_count_col==3 || zero_count_dia==3 || zero_count_dia2==3 ){
            cout<<"Game::Board: ZERO WON";
            return symbol::ZERO;
        }

        if(cross_count_row==3 || cross_count_col==3 || cross_count_dia==3 || cross_count_dia2==3){

            cout<<"Game::Board: CROSS WON";
            return symbol::CROSS;
        }


        // looking for draw
        bool space=false;
        for(int i=0;i<SIZE_GAME_BOARD;i++){

            for(int j=0;j<SIZE_GAME_BOARD;j++){
                if(gameBoard[i][j]==-1){
                    space = true;
                    break;
                }
            }
            if(space) break;
        }

        if(!space){
            cout<<"Game::Board: DRAW";
            return symbol::DRAW;
        }

        cout<<"Game::Board: PLAY";
        return symbol::PLAY;
        
    

}



// print board

void GameBoard::printBoard(){
        cout<<" \n";
        for(int i=0;i<SIZE_GAME_BOARD;i++){

            for(int j=0;j<SIZE_GAME_BOARD;j++){
                if(gameBoard[i][j]==-1){
                    cout<<" ---";
                }else{
                    cout<<" "<<gameBoard[i][j]<<" ";
                }
            }
            cout<<" \n";
        }
}