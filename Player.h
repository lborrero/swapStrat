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

class TokenTypeVO;

class Player
{	
    TokenTypeVO* playerTokens;
public:
	void setTokens(TokenTypeVO tokenArray[]);
	TokenTypeVO* getTokens();
};

#endif
