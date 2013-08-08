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
#include "tokenTypeVO.h"
#include <vector>
#include "Player.h"
#include <sstream>

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
		Player players[NUMBER_OF_PLAYERS];
        Player currentPlayer;
        tokenType currentTokenBeingPlayed;
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
		Player getPlayer(int);
        
        void startGame();
        Player currentPlayersTurn();
        void changeToNextPlayersTurn();
        int getGameState();
        int getMatchState();
        void placeTheTokenOnTheBoard(tokenType, int, int);
        
        void playerSelectedToken(tokenType selectedToken);
        int findTokenInPlayerTokens(tokenType t, Player p);
	};
}
#endif