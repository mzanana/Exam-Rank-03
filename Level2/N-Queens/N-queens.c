#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	valid(int *board, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (col == board[i] || (board[i] - col == i - row) || (board[i] - col == row - i))
			return 0;
	}
	return 1;
	
}

void	solve(int *board, int row, int size)
{
	if (row == size)
	{
		for (int i = 0; i < size; i++)
		{
			printf("%d", board[i]);
			if (i < size - 1)
				printf(" ");
		}
		printf("\n");
		return ;
	}
    int col = 0;
    while (col < size)
	{
		if (valid(board, row, col))
		{
			board[row] = col; // in row 'row' the queen in is column 'col'
			solve(board, row + 1, size);
		}
		col++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int size = atoi(av[1]);
	int board[size];
	solve(board, 0, size);
	return 0;
}
