/*
 *  gameController.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "gameController.h"

GameController::GameController(){
	gameModel.setBoardValues(6, 6);
}

void GameController::printboard(){
	tileSpaceVO* pboard = gameModel.getBoard();
	int * pboardInInts = new int [gameModel.TOTAL];
	for(int i=0; i<gameModel.TOTAL; i++)
	{
		pboardInInts[i] = static_cast<tileSpaceVO>(pboard[i]).getTokenType();
	}
	
    gameView.drawBoard(pboardInInts, gameModel.ROW, gameModel.COL);
}

void GameController::printPlayerTokens(){
	Player p1 = gameModel.getPlayer(0);
	Player p2 = gameModel.getPlayer(1);
	gameView.drawPlayer(p1.getName());
	gameView.drawPlayerTokens(p1.get)
}