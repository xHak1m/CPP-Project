#include <iostream>

using namespace std;

// Print the Board
void printBoard(char board[3][3]) {
	cout << "\nTic-Tac-Toe Board:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

// Check for a Winner
bool checkWin(char board[3][3], char player) {
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
	}
	
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
	
	return false;
}

// Game Loop
int main() {
	char board[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};
	
	int moves = 0;
	char player = 'X';
	
	while (moves < 9) {
		printBoard(board);
		
		int choice;
		cout << "Player " << player << ", enter a number (1-9): ";
		cin >> choice;
		
		if (choice < 1 || choice > 9) {
			cout << "Invalid input. Try again.\n";
			continue;
		}
		
		int row = (choice - 1) / 3;
		int col = (choice - 1) % 3;
		
		if (board[row][col] == 'X' || board[row][col] == 'O') {
			cout << "Spot already taken. Try again.\n";
			continue;
		}
		
		board[row][col] = player;
		moves++;
		
		if (checkWin(board, player)) {
			printBoard(board);
			cout << "Player " << player << " wins!" << endl;
			return 0;
		}
		
		// Switch player
		player = (player == 'X') ? 'O' : 'X';
	}
	
	// If no winner, it's a draw
	printBoard(board);
	cout << "It's a draw!" << endl;
	
	return 0;
}