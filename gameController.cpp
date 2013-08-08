/*
 *  gameController.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "gameController.h"

namespace swapStratCpp {
	GameController::GameController(){
		gameModel.setBoardValues(6, 6);
		gameModel.setPlayers();
	}

	void GameController::printboard(){
		tileSpaceVO* pboard = gameModel.getBoard();
		int * pboardInInts = new int [gameModel.TOTAL];
		for(int i=0; i<gameModel.TOTAL; i++)
		{
			pboardInInts[i] = static_cast<tileSpaceVO>(pboard[i]).getTokenTypeFromTile();
		}
		
		gameView.drawBoard(pboardInInts, gameModel.ROW, gameModel.COL);
	}
    
    void GameController::startGame(){
        gameModel.startGame();
        printboard();
        printPlayerTokens();
        do {
            havePlayerSelectAToken(gameModel.currentPlayersTurn());
            gameModel.changeToNextPlayersTurn();
        }while (gameModel.getGameState() == IN_GAME && gameModel.getMatchState() == PLACING_TOKENS);
    }
    
	void GameController::printPlayerTokens(){
        for(int j=0; j<NUMBER_OF_PLAYERS; j++){
            Player player = gameModel.getPlayer(j);
            gameView.drawPlayer(player.getPlayerName());
            tokenType* tp = player.getPlayerTokens();
            int tokenList[NUMBER_OF_TOKENS];
            for(int i=0; i<NUMBER_OF_TOKENS; i++)
            {
                tokenList[i] = tp[i];
            }
            gameView.drawPlayerTokens(tokenList, NUMBER_OF_TOKENS);
        }
	}

    void GameController::havePlayerSelectAToken(Player p){
        cout << "\n";
        cout << p.getPlayerName() << ", select one of your tokens.\nAvailable options: 1, 2, 3, 4, 5, 6." << "\n";
        cout << "- ";
        tokenType selectedToken = T12;
//        cin >> selectedToken;
        selectedToken--;
        gameModel.playerSelectedToken(selectedToken);
        cout << "You have selected token: "; gameView.drawTokenType(p.getPlayerToken(selectedToken)); cout << ".\n";
    }
    
    void GameController::havePlayerPlaceATokenOnBoard(tokenType t){
        cout << "\n";
//        cout << p.getPlayerName() << ", place your token on the board.\nStart with the numbers on the right side of the board, then use the letters on the top of the board.\nHave them seperated by a comma.\nIt should look something like this: 3,AC" << "\n";
        cout << "- ";
//        gameModel->placeTheTokenOnTheBoard(t, x, y);
    }
}