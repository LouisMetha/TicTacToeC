#include <stdio.h>

char board[3][3];

void inti_board() {
	int i, j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void display() {
	int i, j;

	for (i = 0; i < 3; i++) {
		printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);

		if (i != 2) {
			printf("\n---|---|---\n");
		}
	}
	
	printf("\n");
}

int checkWinner(char player) {
	int i, j;

	// row
	for (i = 0; i < 3; i++) {
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
			return 1;
		}
	}

	// col
	for (j = 0; j < 3; j++) {
		if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
			return 1;
		}
	}

	// diag
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return 1;
	}

	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return 1;
	}
	
	return 0;
}

void play(char player) {

	int row, col;
	printf("Player %c's turn --- \n", player);

	do {
		printf("Enter row (1-3): ");
		scanf_s("%d", &row);
		printf("Enter col (1-3): ");
		scanf_s("%d", &col);
		row--;
		col--;
	} while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

	board[row][col] = player;

}

void run() {
	
	char player = 'X';
	int i;
	
	inti_board();
	display();

	for (i = 0; i < 9; i++) {
		play(player);
		display();

		if (checkWinner(player)) {
			printf("Player %c is the winner.\n", player);
			return;
		}
		player = (player == 'X' ? 'O' : 'X');
	}
	printf("It's a draw!\n");
}

void main() {
	run();
	
}

