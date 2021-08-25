#include <stdio.h>
int N;

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
int isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i]==1)
			return 0;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j]==1)
			return 0;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j]==1)
			return 0;

	return 1;
}

int solveNQ(int board[N][N], int col)
{
	/* base case: If all queens are placed
	then return 1 */
	if (col >= N)
		return 1;

	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < N; i++) {
		/* Check if the queen can be placed on
		board[i][col] */
		if (isSafe(board, i, col)) {
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			if (solveNQ(board, col + 1)==1)
				return 1;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			else{
				board[i][col] = 0; // BACKTRACK
			}
				
		}
	}

	/* If the queen cannot be placed in any row in
		this colum col then return 0 */
	return 0;
}

// driver program to test above function
int main()
{
   printf("enter no.of queen: ");
   scanf("%d", &N);

	int board[N][N];
	for(int i=0; i<N;i++){
		for(int j=0;j<N;j++){
			board[i][j] = 0;
		}
	}

	if (solveNQ(board, 0) == 0) {
		printf("Solution does not exist");
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}

	return 0;
}
