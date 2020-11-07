#include "GameBoard.h"
#include <iostream>

using namespace std;

void getTurn(GameBoard& g){
	int x,y;
	cout << "Player " << g.turn << "\'s Turn" << endl;
	bool validTurn = false;
	while(!validTurn){
		cout << "Pick a column (1-3): ";
		cin >> x;
		cout << "Pick a row (1-3): ";
		cin >> y;
		if(g.move(x-1, y-1)){
			validTurn = true;
		}else{
			cout << "Invalid move! Please try again." << endl;
		}
	}
}

void printBoard(vector<vector<char>> board){
	cout << "Current Board State:" <<  endl;
	for(int i=0; i<board.size(); ++i){
		for(int j=0; j<board[i].size(); ++j){
			if(board[i][j] == 0){
				cout << ".";
			}else{
				cout << board[i][j];
			}
		}
		cout << endl;
	}
}

void printWinner(const GameBoard& g){
	int winner;
	if(g.turn == 2) winner = 1;
	else winner = 2;
	cout << "Player " << winner << " is the winner!" << endl;
}

int main(){
	GameBoard g;
	bool gameOver = false;
	while(!gameOver){
		printBoard(g.getBoard());
		getTurn(g);
		if(g.isGameOver()){
			printWinner(g);
			gameOver = true;
		}
	}
	cout << "See ya later!" << endl;
}
