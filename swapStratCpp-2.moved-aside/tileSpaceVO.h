/*
 *  tileSpaceVO.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TILE_SPACE__
#define __TILE_SPACE__

#include "tokenTypeVO.h"

enum tileType{
	
    empty, occupied
	
};

class tileSpaceVO{
public:
    int id;
	
    tokenTypeVO _tokenType;
	
    tileType _tileType;
	
};

#endif