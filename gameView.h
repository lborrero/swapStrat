/*
 *  gameView.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __GAME_VIEW__
#define __GAME_VIEW__

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

namespace swapStratCpp {

	class GameView{
		
	public:
		
		void drawSpace(int);
        void drawTokenType(int);
		
		void drawBoard(int* , int, int);
		
		void drawPlayer(string);
		void drawPlayerTokens(vector<int>& vtt);
        
        char charFromInt(int alphabetPos);
        string lettersFromInt(int pos);
        
        string askUserForIntput();
        void askForPlayerToPlaceToken(string playerName);
	};
	
}

#endif