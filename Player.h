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
#include "TokenTypeUtils.h"
#include <vector>

using namespace std;

namespace swapStratCpp{
	class TokenTypeVO;

	class Player
	{	
		string playerName;
		vector<tokenType> playerTokens;
	public:
		Player();
        ~Player();
		
		void setPlayerTokens(tokenType tokenArray[], int);
		vector<tokenType>& getPlayerTokens();
		tokenType getPlayerToken(int tokenNum);
        
		void setPlayerName(string);
		string getPlayerName();
		
		bool doesPlayerHaveThisToken(tokenType tt);
		void removeATokenFromPlayer(tokenType tt);
	};
}
	
#endif
