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

		
		TokenTypeVO tokenTypeArray[NUMBER_OF_TOKENS] = {TokenTypeVO(T12), 
														TokenTypeVO(T13), 
														TokenTypeVO(T14), 
														TokenTypeVO(T23), 
														TokenTypeVO(T24), 
														TokenTypeVO(T34)};
		
		cout << "--" << endl;
		for(int i=0; i<6; i++)
		{
			cout << tokenTypeArray[i].getTokenType() << endl;
		}
		
		cout << "-NUMBER_OF_PLAYERS-" << endl;
		for (int i=0; i<NUMBER_OF_PLAYERS; i++) 
		{
			players[i].setPlayerTokens(tokenTypeArray);	
		}
		
	}

	Player GameModel::getPlayer(int player){
		cout << "-players[player]B: " << &players[player] << endl;
		TokenTypeVO* tt = players[player].getPlayerTokens();
		cout << "-www-" << endl;
		for(int i=0; i<6; i++)
		{
			//cout << tt[i].getTokenType() << endl;
		}
		return players[player];
	}
}