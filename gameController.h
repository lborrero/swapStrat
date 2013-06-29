/*
 *  gameController.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __GAME_CONTROLLER__
#define __GAME_CONTROLLER__

#include "gameModel.h"
#include "gameView.h"

namespace swapStratCpp {

	class GameController
	{
		GameModel gameModel; //why can't i do : gameModel(6, 6); here ?
		GameView gameView;
		
	public:
		GameController();
		void printboard();
	};
	
}

#endif