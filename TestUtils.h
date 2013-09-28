/*
 *  TestUtils.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-09-27.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

class TestUtils {
public:
	static int returningint2(){
		return 10;
	}
	
	static int returningint(){
		return returningint2();
	}
};

