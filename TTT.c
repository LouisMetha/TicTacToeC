#include <stdio.h>
#include <time.h>

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

void human_play(char player) {

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

void computer_play(char player) {
	int row, col;
	char opponent = 'X';

	printf("Player %c's turn (Computer) --- \n", player);

	// look for winning move
	for (row = 0; row < 3; row++) {
		for (col = 0; col < 3; col++) {
			if (board[row][col] == ' ') {
				board[row][col] = player;
				if (checkWinner(player)) {
					return;
				}
				else {
					board[row][col] = ' ';
				}
			}
		}
	}

	// look for opponent's winning move

	for (row = 0; row < 3; row++) {
		for (col = 0; col < 3; col++) {
			if (board[row][col] == ' ') {
				board[row][col] = opponent;
				if (checkWinner(opponent)) {
					board[row][col] = player;
					return;
				}
				else {
					board[row][col] = ' ';
				}
			}
		}
	}

	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (board[row][col] != ' ');

	board[row][col] = player;
}

void run() {
	
	char player = 'X';
	int i;
	int mode;

	srand(time(NULL));

	inti_board();
	display();
	
	printf("1 = HumanVsHuman | 2 = HumanVsComputer | Enter Mode: ");
	scanf_s("%d", &mode);

	for (i = 0; i < 9; i++) {
		if (mode == 1) {
			human_play(player);
		}
		else {
			if (i % 2 == 0) {
				human_play(player);
			}
			else {
				computer_play(player);
			}
		}
		
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

