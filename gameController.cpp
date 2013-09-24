/*
 *  gameController.cpp
 *  swapStratCpp
 *
 *  Created by Leonardo Borrero Luz on 13-06-22.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "gameController.h"

namespace swapStratCpp {
	GameController::GameController(){
		gameModel.setBoardValues(6, 6);
		gameModel.setPlayers();
	}

	void GameController::printboard(){
		vector<tileSpaceVO> pboard = gameModel.getBoard();
		int * pboardInInts = new int [gameModel.TOTAL];
		for(int i=0; i<gameModel.TOTAL; i++)
		{
			pboardInInts[i] = pboard[i].getTokenTypeFromTile();
		}
		
		gameView.drawBoard(pboardInInts, gameModel.ROW, gameModel.COL);
	}
    
    void GameController::startGame(){
        gameModel.startGame();
        printboard();
        printPlayerTokens();
        do {
            havePlayerSelectAToken(gameModel.currentPlayersTurn());
            havePlayerPlaceATokenOnBoard();
			verifyBoardMatches();
            gameModel.changeToNextPlayersTurn();
        }while (gameModel.getGameState() == IN_GAME && gameModel.getMatchState() == PLACING_TOKENS);
    }
	
	void GameController::verifyBoardMatches(){
		gameModel.verifyMatches();
	}
    
	void GameController::printPlayerTokens(){
        for(int j=0; j<NUMBER_OF_PLAYERS; j++){
            Player *player = &gameModel.getPlayer(j);
            gameView.drawPlayer((*player).getPlayerName());
            printAPlayersTokens(*player);
        }
	}
    
    void GameController::printAPlayersTokens(Player& p){
		vector<tokenType> *tempVect = &p.getPlayerTokens();
		vector<int> intVector;
		for (int i=0; i<(*tempVect).size(); i++) {
			intVector.push_back((*tempVect).at(i));
		}
        gameView.drawPlayerTokens(intVector);
    }

    void GameController::havePlayerSelectAToken(Player p){
        cout << "\n";
        cout << p.getPlayerName() << ", select one of your tokens: "; printAPlayersTokens(p);
        cout << "- ";
        
        string s;
        bool player_has_select_a_token = false;
        cout << "Enter a token type" << gameView.askUserForIntput();
        while (!player_has_select_a_token){
            cin >> s;
            tokenType selectedToken = TokenTypeUtils::getTokenTypeFromString(s);
            if(selectedToken == none){
                cout << "Not a valid tokenType.\n";
                cout << "Try again" << gameView.askUserForIntput();
            }else{
				if(gameModel.doesCurrentPlayerHaveThisToken(selectedToken)){
					cout << "You have selected token type "; gameView.drawTokenType(selectedToken); cout <<".\n";
					player_has_select_a_token = true;
					gameModel.chooseCurrentSelectedToken(selectedToken);
					gameModel.removeThisTokenFormCurrentPlayer(selectedToken);
				}else{
					cout << p.getPlayerName() << ", you do not have this token.\n";
					cout << "Select one of these tokens: "; printAPlayersTokens(p);
					cout << gameView.askUserForIntput();
				}
            }
        }
    }
    
    int GameController::xCoordFromStringToInt(string input){
        string comparativeString;
        int i = 0;
        bool matchFound = false;
        while(i < gameModel.getBoardHeight() && !matchFound){
            string comparativeString = gameView.lettersFromInt(i);
            if(comparativeString.compare(input) == 0){
                matchFound = true;
            }else{
                i++;
            }
        }
        if(matchFound){
            return i;
        }else{
            return -1;
        }
    }
    
    int GameController::yCoordFromStringToInt(string input){
        int yCoord = -1;
        stringstream(input) >> yCoord;
        return yCoord;
    }
    
    void GameController::havePlayerPlaceATokenOnBoard(){
        Player p = gameModel.currentPlayersTurn();
        gameView.askForPlayerToPlaceToken(p.getPlayerName());
        string s;
        bool player_has_select_a_boardSpace = false;
        while (!player_has_select_a_boardSpace){
            cin >> s;
            std::vector<std::string> spliCoords = StringUtils::split(s, ',');
            int xCoord = -1;
            int yCoord = -1;
            
            if(spliCoords.size() == 2){
                xCoord = xCoordFromStringToInt(spliCoords[1]);
                yCoord = yCoordFromStringToInt(spliCoords[0]);
                if(xCoord != -1 && yCoord != -1){
                    player_has_select_a_boardSpace = true;
                    cout << "You have selected tile " << yCoord << "," << gameView.lettersFromInt(xCoord) <<".\n";
                    gameModel.placeTheTokenOnTheBoard(gameModel.getCurrentTokenBeingPlayed(), xCoord, yCoord);
                    printboard();
                }
            }
            if(!player_has_select_a_boardSpace){
                cout << "Not a valid space coordinate.\n";
                cout << "Try again" << gameView.askUserForIntput();
            }
        }
    }
}