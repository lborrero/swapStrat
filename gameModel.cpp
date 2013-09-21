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
		currentPlayerIndex = 0;
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
		setGameState(IN_GAME);
    }
    
    Player GameModel::currentPlayersTurn(){
        return players[currentPlayerIndex];
    }
    
    void GameModel::changeToNextPlayersTurn(){
        currentPlayerIndex = (currentPlayerIndex+1)%NUMBER_OF_PLAYERS;
    }
	
	void GameModel::setGameState(gameState gs){
		previousGameState = currentGameState;
		currentGameState = gs;
	}
    
    int GameModel::getGameState(){
        return currentGameState;
    }
    
    int GameModel::getMatchState(){
        return 0;
    }
    
    tileSpaceVO GameModel::selectABoardPlaceFromString(string boardPlace){
        //toDO done.
        return tileSpaceVO();
    }
    
    void GameModel::placeTheTokenOnTheBoard(tokenType tt, int x, int y){
        int boardPlacement = y*COL + x;
        board[boardPlacement].setTokenType(tt);
    }
    
    void GameModel::chooseCurrentPlayerSelectedToken(tokenType selectedToken){
        vector<tokenType> *tArray = &currentPlayersTurn().getPlayerTokens();
        currentTokenBeingPlayed = (*tArray).at(findTokenInPlayerTokens(currentPlayersTurn(), selectedToken));
		(*tArray).erase((*tArray).begin()+findTokenInPlayerTokens(currentPlayersTurn(), selectedToken));
    }
	
    int GameModel::findTokenInPlayerTokens(Player p, tokenType t){
        vector<tokenType> *tArray = &p.getPlayerTokens();
        for(int i=0; i<(*tArray).size(); i++){
            if (t == (*tArray).at(i)) {
                return i;
            }
        }
        return -1;
    }
}