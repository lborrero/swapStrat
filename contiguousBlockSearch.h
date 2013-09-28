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

#include <iostream>
#include <vector>
#include <math.h>

class ContiguousBlockSearch{
public:
	static bool verifyDouble(vector<int>& v, int valueToErase){
		vector<int> *negativeLoop = &v;
		for (int i=(*negativeLoop).size()-1; i>=0; i--) {
			if((*negativeLoop).at(i) == valueToErase){
				return true;
			}
		}
		return false;
	}
	
	static void recursiveRight(vector<int>& idCollector, int arrs[], int counter, int width, int height){
		int checkerInt = (counter+1)%(width+1);
		cout << "recursiveRight: " << checkerInt << endl;
		if (arrs[counter] == 0 || checkerInt == 0 || counter > (width*height)-1) {
			return;
		}else{
			cout << &idCollector << " ";
			if(!verifyDouble(idCollector, counter)){
				idCollector.push_back(counter);
			}
			cout << counter << ": " << arrs[counter] << endl;
			recursiveRight(idCollector, arrs, ++counter, width, height);
			return;
		}
	}
	
	static void recursiveLeft(vector<int>& idCollector, int arrs[], int counter, int width, int height){
		int checkerInt = (counter+1)%(width+1);
		cout << "recursiveLeft: " << checkerInt << endl;
		if (arrs[counter] == 0 || checkerInt == 0) {
			return;
		}else{
			cout << &idCollector << " ";
			if(!verifyDouble(idCollector, counter)){
				idCollector.push_back(counter);
			}
			cout << counter << ": " << arrs[counter] << endl;
			recursiveLeft(idCollector, arrs, --counter, width, height);
			return;
		}
	}
	
	static void recursiveTop(vector<int>& idCollector, int arrs[], int counter, int width, int height){
		cout << "recursiveTop: " << counter << endl;
		if (arrs[counter] == 0 || counter < 0) {
			return;
		}else{
			cout << &idCollector << " ";
			if(!verifyDouble(idCollector, counter)){
				idCollector.push_back(counter);
			}
			cout << counter << ": " << arrs[counter] << endl;
			counter = counter - width;
			recursiveTop(idCollector, arrs, counter, width, height);
			return;
		}
	}
	
	static void recursiveBottom(vector<int>& idCollector, int arrs[], int counter, int width, int height){
		cout << "recursiveBottom: " << counter << endl;
		if (arrs[counter] == 0 || counter > (width*height)-1) {
			return;
		}else{
			cout << &idCollector << " ";
			if(!verifyDouble(idCollector, counter)){
				idCollector.push_back(counter);
			}
			cout << counter << ": " << arrs[counter] << endl;
			counter = counter + width;
			recursiveBottom(idCollector, arrs, counter, width, height);
			return;
		}
	}
	
	static void verifyTopBottomLeftAndRight(vector<int>& idCollector, int intArray[], int placement, int width, int height){
		recursiveRight(idCollector, intArray, placement, width, height);
		recursiveLeft(idCollector, intArray, placement, width, height);
		recursiveTop(idCollector, intArray, placement, width, height);
		recursiveBottom(idCollector, intArray, placement, width, height);
	}
	
	static int coordToIndex(int xPos, int yPos, int width){
		return yPos*width+xPos;
	}
	
	static int indexToCoordX(int coordIndex, int width){
		return coordIndex%width;
	}
	
	static int indexToCoordY(int coordIndex, int width){
		return floor(coordIndex/width);
	};
	
	static vector<int> returnContiguousFromTile(int intArray2[], int width2, int height2, int initialCoord_x2, int initialCoord_y2){
		int width = 10;
		int height = 5;
		
		int initialCoord_x = 4;
		int initialCoord_y = 2;
		
		int intArray[]={1, 1, 1, 0, 0, 0, 1, 1, 1, 0,
						0, 0, 1, 1, 0, 1, 0, 0, 1, 0,
						0, 0, 0, 1, 1, 1, 0, 1, 1, 1,
						0, 0, 0, 0, 0, 1, 1, 1, 0, 1,
						0, 0, 0, 0, 0, 0, 0, 0, 1, 1};
		
		vector<int> giveMeIds;
		int previousGiveMeIdsSize = giveMeIds.size();
		cout << intArray << endl;
		int placement = coordToIndex(initialCoord_x, initialCoord_y, width);
		
		verifyTopBottomLeftAndRight(giveMeIds, intArray, placement, width, height);
		
		while(giveMeIds.size() != previousGiveMeIdsSize){
			previousGiveMeIdsSize = giveMeIds.size();
			for (int i=giveMeIds.size()-1; i>=0; i--) {
				cout << "Checking id: " << giveMeIds.at(i) << "." << endl;
				verifyTopBottomLeftAndRight(giveMeIds, intArray, giveMeIds.at(i), width, height);
			}
			cout << "previousGiveMeIdsSize: " << previousGiveMeIdsSize << ". " << "giveMeIds: " << giveMeIds.size() << "." << endl;
		}
		
		cout << giveMeIds.size() << endl;
		for (long index=0; index<(long)giveMeIds.size(); ++index) cout << giveMeIds.at(index) << " ";
		cout << endl;
		
		int colomnMatch = 0;
		int rowMatch = 0;
		cout << endl;
		for(int i=0; i<width*height; i++){
		int checkerInt = (i+1)%(width);
			bool isAmatch = false;
			for(int j=0; j<giveMeIds.size(); j++){
				if(i == giveMeIds.at(j)){
					isAmatch = true;
				}
			}
			if(isAmatch){
				cout << "X";
			}else{
				cout << intArray[i];
			}
			if(checkerInt == 0){
				cout << endl;
			}
			
			
		}
		cout << endl;
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
			
		return giveMeIds;
	}
};


#endif /* defined(__swapStratCpp__ContiguousBlockSearch__) */