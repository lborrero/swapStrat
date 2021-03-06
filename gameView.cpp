/*
 *  gameView.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "gameView.h"

namespace swapStratCpp {

	void GameView::drawSpace(int tileSpaceType){
		string s;
		switch (tileSpaceType) {
			case 1:
				s = "[T12]";
				break;
			case 2:
				s = "[T13]";
				break;
			case 3:
				s = "[T14]";
				break;
			case 4:
				s = "[T23]";
				break;
			case 5:
				s = "[T24]";
				break;
			case 6:
				s = "[T34]";
				break;
			default:
				s = "[   ]";
				break;
		}
		cout << s;
	}

    
    void GameView::drawTokenType(int tokenType){
		string s;
		switch (tokenType) {
			case 1:
				s = "[T12]";
				break;
			case 2:
				s = "[T13]";
				break;
			case 3:
				s = "[T14]";
				break;
			case 4:
				s = "[T23]";
				break;
			case 5:
				s = "[T24]";
				break;
			case 6:
				s = "[T34]";
				break;
			default:
				s = "[   ]";
				break;
		}
		cout << s;
	}

	void GameView::drawBoard(int* board, int WIDTH, int HEIGHT){
		int n,m, p;
        cout << "  ";
        for (p=0;p<HEIGHT;p++)
		{
            cout << "  " << lettersFromInt(p) << " ";
        }
        cout << "\n";
		for (n=0;n<HEIGHT;n++)
		{
            cout << n << " ";
			for (m=0;m<WIDTH;m++)
			{
				drawSpace(board[n*WIDTH+m]);
			}
			cout << "\n";
        }
		cout << "\n";
    }
    
    char GameView::charFromInt(int alphabetPos){
        char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        return alphabet[alphabetPos % 26];
    }
    
    string GameView::lettersFromInt(int pos){
        stringstream output;
        output << charFromInt(pos/26);
        output << charFromInt(pos);
        return output.str();
    }
    
	void GameView::drawPlayer(string playerName){
		cout << playerName << ": ";
	}

	void GameView::drawPlayerTokens(vector<int>& vtt){
		for(int i=0; i<vtt.size(); i++){
			drawTokenType(vtt.at(i));
            cout << ",";
		}
		cout << "\n";
	}
    
    void GameView::askForPlayerToPlaceToken(string playerName){
        cout << "\n";
        cout << playerName << ", place your token on the board.\nStart with the numbers on the right side of the board, then use the letters on the top of the board.\nHave them seperated by a comma.\nIt should look something like this: 3,AC" << "\n";
        cout << askUserForIntput();
        
    }
    
    string GameView::askUserForIntput(){
        return " :";
    }
}