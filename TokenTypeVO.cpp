/*
 *  tokenTypeVO.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "tokenTypeVO.h"

TokenTypeVO::TokenTypeVO(){
	_tokenType = none;
}

TokenTypeVO::TokenTypeVO(tokenType tt)
{
	_tokenType = tt;
}