/*
 *  TokenTypeUtils.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "TokenTypeUtils.h"

namespace swapStratCpp {

	TokenTypeUtils::TokenTypeUtils(){
		_tokenType = none;
	}

	TokenTypeUtils::TokenTypeUtils(tokenType tt)
	{
		_tokenType = tt;
	}
    
    tokenType TokenTypeUtils::getTokenTypeFromString(std::string s){
        if(s.compare("T12") == 0){
            return T12;
        }
        if(s.compare("T13") == 0){
            return T13;
        }
        if(s.compare("T14") == 0){
            return T14;
        }
        if(s.compare("T23") == 0){
            return T23;
        }
        if(s.compare("T24") == 0){
            return T24;
        }
        if(s.compare("T34") == 0){
            return T34;
        }
        return none;
    }
}