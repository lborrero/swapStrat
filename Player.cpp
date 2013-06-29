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
	
	void Player::setPlayerName(string s){
		playerName = s;
	}
	
	string Player::getPlayerName(){
		return playerName;
	}
	
	void Player::setTokens(TokenTypeVO tokenArray[]){
		playerTokens = tokenArray;
	}
	
	TokenTypeVO* Player::getTokens(){
		return playerTokens;
	}
}
