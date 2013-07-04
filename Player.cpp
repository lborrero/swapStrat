/*
 *  Player.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "Player.h"

namespace swapStratCpp {
	
	Player::Player(){
		playerName = "DefaultPlayerName";
	}
    
    Player::~Player(){
    }
	
	void Player::setPlayerName(string s){
		playerName = s;
	}
	
	string Player::getPlayerName(){
		return playerName;
	}
	
	void Player::setPlayerTokens(tokenType tokenArray[], int numberOfTokens){
        playerTokens = new tokenType[numberOfTokens];
		for(int i=0; i<numberOfTokens; i++)
		{
            playerTokens[i] = tokenArray[i];
		}
	}
	
	tokenType* Player::getPlayerTokens(){
		return playerTokens;
	}
}
