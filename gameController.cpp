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
            havePlayerPlaceATokenOnBoard();
            gameModel.changeToNextPlayersTurn();
        }while (gameModel.getGameState() == IN_GAME && gameModel.getMatchState() == PLACING_TOKENS);
    }
    
	void GameController::printPlayerTokens(){
        for(int j=0; j<NUMBER_OF_PLAYERS; j++){
            Player player = gameModel.getPlayer(j);
            gameView.drawPlayer(player.getPlayerName());
            printAPlayersTokens(player);
        }
	}
    
    void GameController::printAPlayersTokens(Player p){
        tokenType* tp = p.getPlayerTokens();
        int tokenList[NUMBER_OF_TOKENS];
        for(int i=0; i<NUMBER_OF_TOKENS; i++)
        {
            tokenList[i] = tp[i];
        }
        gameView.drawPlayerTokens(tokenList, NUMBER_OF_TOKENS);
    }

    void GameController::havePlayerSelectAToken(Player p){
        cout << "\n";
        cout << p.getPlayerName() << ", select one of your tokens: "; printAPlayersTokens(p);
        cout << "- ";
        
        string s;
        bool player_has_select_a_token = false;
        cout << "Enter a token type" << gameView.askUserForIntput();
        while (!player_has_select_a_token){
            cin >> s;
            tokenType selectedToken = TokenTypeUtils::getTokenTypeFromString(s);
            if(selectedToken == none){
                cout << "Not a valid tokenType.\n";
                cout << "Try again" << gameView.askUserForIntput();
            }else{
                cout << "You have selected token type "; gameView.drawTokenType(selectedToken); cout <<".\n";
                gameModel.chooseCurrentPlayerSelectedToken(selectedToken);
                player_has_select_a_token = true;
            }
        }
    }
    
    void GameController::havePlayerPlaceATokenOnBoard(){
        Player p = gameModel.currentPlayersTurn();
        cout << "\n";
        cout << p.getPlayerName() << ", place your token on the board.\nStart with the numbers on the right side of the board, then use the letters on the top of the board.\nHave them seperated by a comma.\nIt should look something like this: 3,AC" << "\n";
        cout << gameView.askUserForIntput();
        string s;
        bool player_has_select_a_boardSpace = false;
        while (!player_has_select_a_boardSpace){
            cin >> s;
            tokenType selectedToken = TokenTypeUtils::getTokenTypeFromString(s);
            if(selectedToken == none){
                cout << "Not a valid tokenType.\n";
                cout << "Try again" << gameView.askUserForIntput();
            }else{
                cout << "You have selected token type "; gameView.drawTokenType(selectedToken); cout <<".\n";
                gameModel.chooseCurrentPlayerSelectedToken(selectedToken);
//                gameModel->placeTheTokenOnTheBoard(t, x, y);
                player_has_select_a_boardSpace = true;
            }
        }
    }
}