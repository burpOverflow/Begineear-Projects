#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]; //t-t-t matrix

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void display_matrix(void);

int main()
{
	char done;
	printf("Tic Tac Toe!\n");
	printf("play with computer\n");

	done = ' ';
	init_matrix();
	do{
		display_matrix();
		get_player_move();
		done = check(); /* check if winner */
		if (done != ' ') break;
		get_computer_move();
		done = check();
	} while (done == ' ');
	if (done == 'x')
		printf("You Won!\n");
	if (done == 'o')
		printf("Computer Own!\n");
	display_matrix(); // how final position
	return 0;
}

/* Initialize the matrix. */
void init_matrix(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

//display matrix on the screen
void display_matrix(void)
{
	for (int t = 0; t < 3; t++)
	{
		printf(" %c | %c | %c \n", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2)
		{
			printf("---|---|---\n");
		}
	}
}

/* Get a player's move. */
void get_player_move(void)
{
	int x, y;
	printf("Enter X,Y coordinates for your move: \n");
	scanf("%d", &x);
	scanf("%d", &y);
	x--;
	y--;
	
	if (matrix[x][y] == ' '){
		matrix[x][y] = 'x';
	}
	else{
		printf("Invalid move try again!\n");
		get_player_move();
	}
}

// check if winner
char check(void)
{
	// check row
	for (int i = 0; i < 3; i++){
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]){
			return matrix[i][0];
		}
	}
	// check column
	for (int i = 0; i < 3; i++){
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]){
			return matrix[0][i];
		}
	}
	// check diagonals
	for (int i = 0; i < 3; i++){
		if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]){
			return matrix[0][0];
		}
		if (matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]){
			return matrix[0][1];
		}
		if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]){
			return matrix[0][2];
		}
	}
	return ' ';
}
/* Get a move from the computer. */
void get_computer_move(void){
	int i, j;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++)
			if(matrix[i][j]==' ') break;
		if(matrix[i][j]==' ') break;
	}
	if(i*j==9) {
	printf("draw\n");
	exit(0);
	}else{
		matrix[i][j] = 'o';
	}
	
}

