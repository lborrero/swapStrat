/*
 *  gameView.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "gameView.h"

void GameView::drawSpace(int tileSpaceType){
	
    string s;
	
    switch (tileSpaceType) {
			
        case 1:
			
            s = "[T12]";
			
            break;
			
        case 2:
			
            s = "[T13]";
			
            break;
			
        case 3:
			
            s = "[T14]";
			
            break;
			
        case 4:
			
            s = "[T23]";
			
            break;
			
        case 5:
			
            s = "[T24]";
			
            break;
			
        case 6:
			
            s = "[T34]";
			
            break;
			
        default:
			
            s = "[   ]";
			
            break;
			
    }
	
    cout << s;
	
}



void GameView::drawBoard(int* board, int WIDTH, int HEIGHT){
	
    int n,m;
	
    for (n=0;n<HEIGHT;n++)
		
    {
		
        for (m=0;m<WIDTH;m++)
			
        {
			
            drawSpace(board[n*WIDTH+m]);
			
        }
		
        cout << "\n";
		
    }
	
    cout << "\n";
	
}

void GameView::drawPlayer(string playerName){
	cout << playerName << ": ";
}

void GameView::drawPlayerTokens(int * playerTokens, int numberOfTokens){
	for(int i=0; i<numberOfTokens; i++){
		cout << playerTokens[i];
	}
	cout << "\n";
}