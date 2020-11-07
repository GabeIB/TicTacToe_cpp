#include "GameBoard.h"
#include <iostream>
#include <string>

using namespace std;

GameBoard::GameBoard() : turn(1), lastMove(2, -1){
	for(int i=0; i<boardSize; ++i){
		board.push_back(vector<char>(boardSize, 0));
	}
}

//returns true if move is valid
//false for invalid move
bool GameBoard::move(int x, int y){
	//if x,y are out of board
	if(!(x < boardSize && x >= 0 && y < boardSize && y >= 0)) return false;
	//if x,y are a location that already has a piece
	if(board[y][x] != 0) return false;

	lastMove = {x,y};
	char userChar;
	if(turn == 1){
		userChar = 'x';
		turn = 2;
	}
	else{
		userChar = 'o';
		turn = 1;
	}
	board[y][x] = userChar;
}

//takes a string and playertoken and count longest consecutive string of playertokens in string
int _countInARow(char playerToken, string s){
	int max = 0;
	int localCount = 0;
	for(int i=0; i<s.length(); ++i){
		if(s[i] == playerToken){
			localCount++;
		}else{
			if(localCount > max) max = localCount;
			localCount = 0;
		}
	}
	if(localCount > max) max = localCount;
	//cout << max << endl;
	return max;
}

//counts the length of the longest consecutive string of tokens in row
int GameBoard::countInARow(char playerToken, int startX, int startY, int itrX, int itrY){
	int x=startX;
	int y=startY;
	while(x<board.size() && x >=0 && y<board.size() && y >= 0){
		x -= itrX;
		y -= itrY;
	}
	x += itrX;
	y += itrY;
	string s = "";
	while(x<board.size() && x >=0 && y<board.size() && y >= 0){
		char c = board[y][x];
		if(c == 0) c = '.';
		s += c;
		x += itrX;
		y += itrY;
	}
	//cout << s << endl;
	return _countInARow(playerToken, s);
}

bool GameBoard::isGameOver(){
	char userChar;
	if(turn == 1) userChar = 'o';
	else userChar = 'x';
	if(countInARow(userChar, lastMove[0], lastMove[1], 1, 0) >= 3 ||
			countInARow(userChar, lastMove[0], lastMove[1], 0, 1) >=3 ||
			countInARow(userChar, lastMove[0], lastMove[1],1,1) >= 3 ||
			countInARow(userChar, lastMove[0], lastMove[1], -1, 1) >= 3){
		return true;
	}
	return false;
}

vector<vector<char>> GameBoard::getBoard(){
	return board;
}
