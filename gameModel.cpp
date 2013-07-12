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
    
    enum gameState{
        INITIALIZING,
        IN_GAME
    };
    
    enum matchState{
        PLACING_TOKENS,
        MOVING_TOKENS
    };
	
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
    
    void GameModel::placeTheTokenOnTheBoard(tokenType, int, int){
    }
}