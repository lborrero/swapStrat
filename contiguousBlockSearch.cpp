/*
 *  contiguousBlockSearch
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-09-21.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "contiguousBlockSearch.h"

bool ContiguousBlockSearch::verifyDouble(vector<int>& v, int valueToErase){
	vector<int> *negativeLoop = &v;
	for (int i=(*negativeLoop).size()-1; i>=0; i--) {
		if((*negativeLoop).at(i) == valueToErase){
			return true;
		}
	}
	return false;
}

void ContiguousBlockSearch::recursiveRight(vector<int>& idCollector, int arrs[], int counter){
	if (arrs[counter] == 0) {
		return;
	}else{
		cout << &idCollector << " ";
		if(!verifyDouble(idCollector, counter)){
			idCollector.push_back(counter);
		}
		cout << counter << ": " << arrs[counter] << endl;
		recursiveRight(idCollector, arrs, ++counter);
		return;
	}
}

void ContiguousBlockSearch::recursiveLeft(vector<int>& idCollector, int arrs[], int counter){
	if (arrs[counter] == 0) {
		return;
	}else{
		cout << &idCollector << " ";
		if(!verifyDouble(idCollector, counter)){
			idCollector.push_back(counter);
		}
		cout << counter << ": " << arrs[counter] << endl;
		recursiveLeft(idCollector, arrs, --counter);
		return;
	}
}

void ContiguousBlockSearch::recursiveTop(vector<int>& idCollector, int arrs[], int counter, int width){
	if (arrs[counter] == 0) {
		return;
	}else{
		cout << &idCollector << " ";
		if(!verifyDouble(idCollector, counter)){
			idCollector.push_back(counter);
		}
		cout << counter << ": " << arrs[counter] << endl;
		counter = counter - width;
		recursiveTop(idCollector, arrs, counter, width);
		return;
	}
}

void ContiguousBlockSearch::recursiveBottom(vector<int>& idCollector, int arrs[], int counter, int width){
	if (arrs[counter] == 0) {
		return;
	}else{
		cout << &idCollector << " ";
		if(!verifyDouble(idCollector, counter)){
			idCollector.push_back(counter);
		}
		cout << counter << ": " << arrs[counter] << endl;
		counter = counter + width;
		recursiveBottom(idCollector, arrs, counter, width);
		return;
	}
}

void ContiguousBlockSearch::verifyTopBottomLeftAndRight(vector<int>& idCollector, int intArray[], int placement, int width){
	recursiveRight(idCollector, intArray, placement);
	recursiveLeft(idCollector, intArray, placement);
	recursiveTop(idCollector, intArray, placement, width);
	recursiveBottom(idCollector, intArray, placement, width);
}

int ContiguousBlockSearch::coordToIndex(int xPos, int yPos, int width){
	return yPos*width+xPos;
}

int ContiguousBlockSearch::indexToCoordX(int coordIndex, int width){
	return coordIndex%width;
}

int ContiguousBlockSearch::indexToCoordY(int coordIndex, int width){
	return floor(coordIndex/width);
}

static vector<int> ContiguousBlockSearch::returnContiguousFromTile(int intArray2[], int width2, int initialCoord_x2, int initialCoord_y2){
	int width = 10;
	int height = 5;
	
	int initialCoord_x = 5;
	int initialCoord_y = 3;
	
	int intArray[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
						0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	vector<int> giveMeIds;
	int previousGiveMeIdsSize = giveMeIds.size();
	cout << intArray << endl;
	arrayDerefernce(intArray);
	int placement = coordToIndex(initialCoord_x, initialCoord_y, width);
	
	verifyTopBottomLeftAndRight(giveMeIds, intArray, placement, width);
	
	while(giveMeIds.size() != previousGiveMeIdsSize){
		for (int i=giveMeIds.size()-1; i>=0; i--) {
			verifyTopBottomLeftAndRight(giveMeIds, intArray, giveMeIds.at(i), width);
		}
		previousGiveMeIdsSize = giveMeIds.size();
	}
	
	cout << giveMeIds.size() << endl;
	for (long index=0; index<(long)giveMeIds.size(); ++index) cout << giveMeIds.at(index) << " ";
    cout << endl;
	
	int colomnMatch = 0;
	int rowMatch = 0;
	
	for(int i=0; i<giveMeIds.size(); i++){
		if(initialCoord_x == indexToCoordX(giveMeIds.at(i), width)){
			colomnMatch++;
		}
	}
	
	for(int i=0; i<giveMeIds.size(); i++){
		if(initialCoord_y == indexToCoordY(giveMeIds.at(i), width)){
			rowMatch++;
		}
	}
	
	cout << "colomnMatch: " << colomnMatch << endl;
	cout << "rowMatch: " << rowMatch << endl;
		
	return;
}