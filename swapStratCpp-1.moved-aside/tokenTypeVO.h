/*
 *  tokenTypeVO.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TOKEN_TYPES__
#define __TOKEN_TYPES__

enum tokenType{
    none,
	
    T12,
	
    T13,
	
    T14,
	
    T23,
	
    T24,
	
    T34,
	
};


class tokenTypeVO{
public:
    int id;
	
    tokenType _tokenType;
	
//    teamType _teamType;
	
};

#endif