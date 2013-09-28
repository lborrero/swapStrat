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
		int tileId = y*getBoardWidth() + x;
		if (tileId>TOTAL || tileId<0 || 
			x < 0 || y < 0 || 
			x > getBoardWidth() || y > getBoardHeight()) {
			return -1;
			cout << "BREAK: - boardTileIDfromCoord";
		}else{
			return tileId;
		}
	}
    
    void GameModel::placeTheTokenOnTheBoard(tokenType tt, int x, int y){
		currentTileBeingPlayed = boardTileIDfromCoord(x,y);
		if(currentTileBeingPlayed == -1){
			cout << "BREAK: - placeTheTokenOnTheBoard";
		}else{
			board.at(boardTileIDfromCoord(x,y)).setTokenType(tt);
		}
		cout << "boardTileIDfromCoord: " << boardTileIDfromCoord(x,y) << " " << x << " " << y << endl;
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

	int GameModel::fromTokenTypeToByteArray(tokenType tt, int level){
		int possibleTokenArrays[7][4] = {
			{0, 0, 0, 0},//none,
			{1, 1, 0, 0},//T12
			{1, 0, 1, 0},//T13
			{1, 0, 0, 1},//T14
			{0, 1, 1, 0},//T23
			{0, 1, 0, 1},//T24
			{0, 0, 1, 1} //T34
		};
		//cout << possibleTokenArrays[1][1] << " vs. " << possibleTokenArrays[tt][level-1] << endl;
		return possibleTokenArrays[tt][level-1];
	}
	
	void GameModel::verifyMatches(){
		int forLevelBoard1[TOTAL];
		int forLevelBoard2[TOTAL];
		int forLevelBoard3[TOTAL];
		int forLevelBoard4[TOTAL];
		for(int i=0; i<TOTAL; i++){
//			cout << fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 1) << ", "<< fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 2) << ", "<< fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 3) << ", "<< fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 4) << endl;
			forLevelBoard1[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 1);
			forLevelBoard2[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 2);
			forLevelBoard3[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 3);
			forLevelBoard4[i] = fromTokenTypeToByteArray(board[i].getTokenTypeFromTile(), 4);
		}
		
		int xPos = ContiguousBlockSearch::indexToCoordX(getCurrentTileBeingPlayed(), getBoardWidth());
		int yPos = ContiguousBlockSearch::indexToCoordY(getCurrentTileBeingPlayed(), getBoardWidth());
		
		vector<vector<int> > matchables;
		
		matchables.push_back(ContiguousBlockSearch::returnContiguousFromTile(forLevelBoard1, getBoardWidth(), getBoardHeight(), xPos, yPos));
		matchables.push_back(ContiguousBlockSearch::returnContiguousFromTile(forLevelBoard2, getBoardWidth(), getBoardHeight(), xPos, yPos));
		matchables.push_back(ContiguousBlockSearch::returnContiguousFromTile(forLevelBoard3, getBoardWidth(), getBoardHeight(), xPos, yPos));
		matchables.push_back(ContiguousBlockSearch::returnContiguousFromTile(forLevelBoard4, getBoardWidth(), getBoardHeight(), xPos, yPos));

		for(int i=0; i<matchables.size(); i++){
			cout << i << " colomnMatch: " << ContiguousBlockSearch::giveMeColomnMatchesForCoord(matchables.at(i), xPos, yPos, getBoardWidth(), getBoardHeight()).size() << endl;
			cout << i << " rowMatch: " << ContiguousBlockSearch::giveMeRowMatchesForCoord(matchables.at(i), xPos, yPos, getBoardWidth(), getBoardHeight()).size() << endl;
		}
	}
	
	void GameModel::findMatcheSequence(){
			findMatcheSequence();
	}
			
}