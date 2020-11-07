#include <vector>

class GameBoard{
private:
	std::vector<std::vector<char>> board;
	std::vector<int> lastMove;
	int boardSize = 3;
public:
	int turn; //which player's turn is it?
	GameBoard();
	bool move(int, int);
	bool isGameOver();
	std::vector<std::vector<char>> getBoard();
	int countInARow(char playerToken, int startX, int startY, int itrX, int itrY);

	//make gameboard noncopyable
	GameBoard& operator=(const GameBoard& other) = delete;
	GameBoard(const GameBoard& other) = delete;
};
