//

//  main.cpp

//  swapStrat

//

//  Created by Leonardo Borrero Luz on 2013-06-19.

//  Copyright (c) 2013 Leonardo Borrero Luz. All rights reserved.

//

#include <exception>
#include "gameController.h"

using namespace	swapStratCpp;

int main(int argc, const char * argv[])
{	
	GameController gc;
	gc.printboard();
	gc.printPlayerTokens();
    
    gc.startGame();
	
    return 0;
}

