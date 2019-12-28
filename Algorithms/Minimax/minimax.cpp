#include<iostream>
using namespace std;

class TicTacToe {
private:
	char board[3][3];
public: 
	TicTacToe();
	bool isWinner(char c);
	bool isFull();
	void drawBoard();
	int minimax(bool);
};

TicTacToe::TicTacToe() {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			board[i][j] = ' ';
	return;
}

bool TicTacToe::isWinner(char c) {
	//row
	if (board[0][0] == c && board[0][1] == c && board[0][2] == c)
		return true;
	else if (board[1][0] == c && board[1][1] == c && board[1][2] == c)
		return true;
	else if (board[2][0] == c && board[2][1] == c && board[2][2] == c)
		return true;
	//cols
	else if (board[0][0] == c && board[1][0] == c && board[2][0] == c)
		return true;
	else if (board[0][1] == c && board[1][1] == c && board[2][1] == c)
		return true;
	else if (board[0][2] == c && board[1][2] == c && board[2][2] == c)
		return true;
	//diagonals
	else if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
		return true;
	else if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
		return true;
	else return false;
}

bool TicTacToe::isFull() {
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (board[i][j] != 'x' && board[i][j] != 'o')
				return false;
	return true;
}

void TicTacToe::drawBoard() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			cout << board[i][j];
		cout << endl;
	}
	return;
}


int main()
{
	return 0;
}