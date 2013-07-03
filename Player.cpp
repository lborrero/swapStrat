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
	
	void Player::setPlayerTokens(TokenTypeVO tokenArray[]){
		cout <<  "setPlayerTokens" << endl;
		for(int i=0; i<6; i++)
		{
			cout << tokenArray[i].getTokenType() << endl;
		}
		//playerTokens = tokenArray;
	}
	
	TokenTypeVO* Player::getPlayerTokens(){
		for(int i=0; i<6; i++)
		{
			cout << playerTokens[i].getTokenType() << endl;
		}
		return playerTokens;
	}
}
