/*
 *  gameModel.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __GAME_MODEL__
#define __GAME_MODEL__

#include "tileSpaceVO.h"
#include "TokenTypeUtils.h"
#include <vector>
#include "Player.h"
#include <sstream>
#include <vector>

#define NUMBER_OF_PLAYERS 2
#define NUMBER_OF_TOKENS 6

//template <class T> // when forewording a template class, do we have to have the template signature fro it to be regognized as a template class?

namespace swapStratCpp {

    enum gameState{
        INITIALIZING,
        IN_GAME
    };
    
    enum matchState{
        PLACING_TOKENS,
        MOVING_TOKENS
    };
	
	class GameModel{
	private:
		tileSpaceVO* board;
		vector<Player> players;
        Player currentPlayer;
		int currentPlayerIndex;
        tokenType currentTokenBeingPlayed;
        gameState previousGameState;
		gameState currentGameState;
        matchState currentMatchState;
		
	public:
		int ROW, COL, TOTAL;
		
		GameModel();
		GameModel(int, int);
		~GameModel();
		
		void setBoardValues(int,int);
		tileSpaceVO* getBoard();
		void setPlayers();
		Player& getPlayer(int);
        
        void startGame();
        Player& currentPlayersTurn();
        void changeToNextPlayersTurn();
        int getGameState();
		void setGameState(gameState gs);
        int getMatchState();
        tokenType getCurrentTokenBeingPlayed(){return currentTokenBeingPlayed;}
        void placeTheTokenOnTheBoard(tokenType, int, int);
        tileSpaceVO selectABoardPlaceFromString(string boardPlace);
            
        bool doesCurrentPlayerHaveThisToken(tokenType tt);
		void removeThisTokenFormCurrentPlayer(tokenType tt);
		void chooseCurrentSelectedToken(tokenType selectedToken);
        
        int getBoardWidth(){return ROW;}
        int getBoardHeight(){return COL;}
	};
}
#endif