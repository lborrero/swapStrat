/*
 *  contiguousBlockSearch.h
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-09-21.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __swapStratCpp__ContiguousBlockSearch__
#define __swapStratCpp__ContiguousBlockSearch__

class ContiguousBlockSearch{
public:
	ContiguousBlockSearch();
	
	bool verifyDouble(vector<int>& v, int valueToErase);
	void recursiveRight(vector<int>& idCollector, int arrs[], int counter);
	void recursiveLeft(vector<int>& idCollector, int arrs[], int counter);
	void recursiveTop(vector<int>& idCollector, int arrs[], int counter, int width);
	void recursiveBottom(vector<int>& idCollector, int arrs[], int counter, int width);
	void verifyTopBottomLeftAndRight(vector<int>& idCollector, int intArray[], int placement, int width);
	int coordToIndex(int xPos, int yPos, int width);
	int indexToCoordX(int coordIndex, int width);
	int indexToCoordY(int coordIndex, int width);
	
	static vector<int> returnContiguousFromTile(int, int, int, int);
}


#endif /* defined(__swapStratCpp__ContiguousBlockSearch__) */