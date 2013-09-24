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
		
		board = vector<tileSpaceVO>(TOTAL);
	}

	GameModel::GameModel(int x, int y){
		ROW = x;
		COL = y;
		TOTAL = ROW*COL;
		
		board = vector<tileSpaceVO>(TOTAL);
	}

	GameModel::~GameModel(){
		board.clear();
	}

	void GameModel::setBoardValues(int x, int y){
		board.clear();
		ROW = x;
		COL = y;
		TOTAL = ROW*COL;
		
		board = vector<tileSpaceVO>(TOTAL);
	}
	
	void GameModel::setBoardWithValueArray(int x, int y, tileSpaceVO tileArray[]){
		board.clear();
		ROW = x;
		COL = y;
		TOTAL = ROW*COL;
		
		board.assign(tileArray, tileArray+TOTAL);
	}

	vector<tileSpaceVO>& GameModel::getBoard()
	{
		return board;
	}

	void GameModel::setPlayers(){
		currentPlayerIndex = 0;
		tokenType tokenTypeArray[NUMBER_OF_TOKENS] = {T12, T12, T13, T13, T14, T14};//, T23, T23, T24, T24, T34, T34};
		for (int i=0; i<NUMBER_OF_PLAYERS; i++) 
		{
			Player tempPlayer;
            stringstream name;
            name << "Player";
            name << i+1;
            
            tempPlayer.setPlayerName(name.str());
			tempPlayer.setPlayerTokens(tokenTypeArray, NUMBER_OF_TOKENS);
			
			players.push_back(tempPlayer);
		}
	}

	Player& GameModel::getPlayer(int player){
		return players[player];
	}
    
    void GameModel::startGame(){
		setGameState(IN_GAME);
    }
    
    Player& GameModel::currentPlayersTurn(){
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
	
	int GameModel::boardTileIDfromCoord(int x, int y){
		int tileId = y*COL + x;
		if (tileId>TOTAL || tileId<0 || 
			x < 0 || y < 0 || 
			x > getBoardWidth() || y < getBoardHeight()) {
			return -1;
		}else{
			return tileId;
		}
	}
    
    void GameModel::placeTheTokenOnTheBoard(tokenType tt, int x, int y){
        board[boardTileIDfromCoord(x,y)].setTokenType(tt);
    }
	
	bool GameModel::doesCurrentPlayerHaveThisToken(tokenType tt){
		return currentPlayersTurn().doesPlayerHaveThisToken(tt);
	}
	
	void GameModel::removeThisTokenFormCurrentPlayer(tokenType tt){
		currentPlayersTurn().removeATokenFromPlayer(tt);
	}
    
    void GameModel::chooseCurrentSelectedToken(tokenType selectedToken){
        currentTokenBeingPlayed = selectedToken;
    }
	
	bool GameModel::verifyMatchAtLevel(tokenType t1, tokenType t2, int level){
	//	int arrayCompare[2][4] = {fromTokenTypeToByteArray(t1), fromTokenTypeToByteArray(t2)};
		
		//if(arrayCompare[0][level] == 1 && arrayCompare[1][level] == 1){
//			return true;
//		}else {
//			return false;
//		}
		return false;
	}
	
	int GameModel::fromTokenTypeToByteArray(tokenType tt, int level){
		int possibleTokenArrays[6][4] = {
			{1, 1, 0, 0},
			{1, 0, 1, 0},
			{0, 1, 1, 0},
			{1, 0, 0, 1},
			{0, 1, 0, 1},
			{0, 0, 1, 1}
		};
		return possibleTokenArrays[tt][level-1];
	}
	
	void GameModel::verifyMatches(){
		int forLevelBoard1[TOTAL];
		int forLevelBoard2[TOTAL];
		int forLevelBoard3[TOTAL];
		int forLevelBoard4[TOTAL];
		for(int i=0; i<TOTAL; i++){
			forLevelBoard1[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 1);
			forLevelBoard2[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 2);
			forLevelBoard3[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 3);
			forLevelBoard4[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 4);
		}
		
		vector<vector<int> > matchables(4);
		
		ContiguousBlockSearch::returnContiguousFromTile(forLevelBoard1, getBoardWidth(), 2, 3);
	}
	
	void GameModel::findMatcheSequence(){
			findMatcheSequence();
	}
			
}