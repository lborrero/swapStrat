/*
 *  Player.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __PLAYER__
#define __PLAYER__

#include <iostream>
#include <string>

using namespace std;

namespace swapStratCpp{
	class TokenTypeVO;

	class Player
	{	
		string playerName;
		TokenTypeVO* playerTokens;
	public:
		Player();
		
		void setTokens(TokenTypeVO tokenArray[]);
		TokenTypeVO* getTokens();
		
		void setPlayerName(string);
		string getPlayerName();
	};
}
	
#endif
