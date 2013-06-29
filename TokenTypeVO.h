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

namespace swapStratCpp {
	enum tokenType{
		none,
		
		T12,
		
		T13,
		
		T14,
		
		T23,
		
		T24,
		
		T34,	
	};

	class TokenTypeVO{
	public:
		tokenType _tokenType;
		TokenTypeVO();
		TokenTypeVO(tokenType);
		
		//    teamType _teamType;
		tokenType getTokenType(){return _tokenType;};
		void setTokenType(tokenType tt){_tokenType = tt;};
	};
}

#endif