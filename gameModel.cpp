/*
 *  gameModel.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "gameModel.h"

namespace swapStratCpp {
	
	GameModel::GameModel(){
		ROW = 2;
		COL = 2;
		TOTAL = ROW*COL;
		
		board = new tileSpaceVO [TOTAL];
	}

	GameModel::GameModel(int x, int y){
		ROW = x;
		COL = y;
		TOTAL = ROW*COL;
		
		board = new tileSpaceVO [TOTAL];
	}

	GameModel::~GameModel(){
		delete []board;
	}

	void GameModel::setBoardValues(int x, int y){
		delete []board;
		ROW = x;
		COL = y;
		TOTAL = ROW*COL;
		
		board = new tileSpaceVO [TOTAL];
	}

	tileSpaceVO* GameModel::getBoard()
	{
		return board;
		
	}

	void GameModel::setPlayers(){
		tokenType tokenTypeArray[NUMBER_OF_TOKENS] = {T12, T13, T14, T23, T24, T34};
		for (int i=0; i<NUMBER_OF_PLAYERS; i++) 
		{
            stringstream name;
            name << "Player";
            name << i+1;
            
            players[i].setPlayerName(name.str());
			players[i].setPlayerTokens(tokenTypeArray, NUMBER_OF_TOKENS);
		}
	}

	Player GameModel::getPlayer(int player){
		return players[player];
	}
    
    void GameModel::startGame(){
    }
    
    Player GameModel::currentPlayersTurn(){
        return players[0];
    }
    
    void GameModel::changeToNextPlayersTurn(){
        
    }
    
    int GameModel::getGameState(){
        return 0;
    }
    
    int GameModel::getMatchState(){
        return 0;
    }
    
    tileSpaceVO GameModel::selectABoardPlaceFromString(string boardPlace){
        //toDO
        return tileSpaceVO();
    }
    
    void GameModel::placeTheTokenOnTheBoard(tokenType, int, int){
        
    }
    
    void GameModel::chooseCurrentPlayerSelectedToken(tokenType selectedToken){
        tokenType* tArray = currentPlayersTurn().getPlayerTokens();
        currentTokenBeingPlayed = tArray[findTokenInPlayerTokens(selectedToken, currentPlayersTurn())];
    }
    
    int GameModel::findTokenInPlayerTokens(tokenType t, Player p){
        tokenType* tArray = p.getPlayerTokens();
        for(int i=0; i<NUMBER_OF_TOKENS; i++){
            if (t == tArray[i]) {
                return i;
            }
        }
        return -1;
    }
}