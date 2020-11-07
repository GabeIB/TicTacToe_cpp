CXX = g++
CXXFLAGS = -std=c++11

tictactoe: terminalClient.o GameBoard.o
	$(CXX) $(CXXFLAGS) -o tictactoe terminalClient.o GameBoard.o

clean:
	rm *.o tictactoe
